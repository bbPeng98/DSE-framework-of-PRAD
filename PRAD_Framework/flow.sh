#!/bin/bash


# echo "------------------ map and pack --------------------"
cd ..
cd ./MetaMapper
#generate rewrite-rules

python3 ./MetaMapper/src/lassen/scripts/gen_code.py
python3 ./MetaMapper/src/lassen/scripts/gen_pe.py
python3 ./MetaMapper/src/lassen/scripts/my_regenerate_peak_rules.py
#map pe
rm ./apps/$1/bin/$1_compute_mapped.json
python3 ./MetaMapper/scripts/map_app.py ./apps/$1/bin/$1_compute.json 0
#map mem

rm ./apps/$1/bin/map_result/$1/$1_to_metamapper.json
cd ./apps/$1/bin
sed -i -e 's/_mapped//g' ./$1_compute_mapped.json
cp /home/dai-dirk/MetaMapper/MetaMapper/libs/*_header.json /home/dai-dirk/MetaMapper/apps/$1/bin/ && cp /home/dai-dirk/MetaMapper/MetaMapper/libs/*_header.json /home/dai-dirk/MetaMapper/MetaMapper/clockwork/ && cp /home/dai-dirk/MetaMapper/MetaMapper/libs/*_header.json /home/dai-dirk/MetaMapper/MetaMapper/garnet/headers/

CLKWRK_PATH=/home/dai-dirk/MetaMapper/MetaMapper/clockwork LD_LIBRARY_PATH=/home/dai-dirk/MetaMapper/MetaMapper/clockwork/lib:/home/dai-dirk/MetaMapper/MetaMapper/coreir/lib LAKE_PATH=/home/dai-dirk/MetaMapper/MetaMapper/src/lake-aha LAKE_CONTROLLERS=/home/dai-dirk/MetaMapper/apps/$1/bin LAKE_STREAM=/home/dai-dirk/MetaMapper/apps/$1/bin COREIR_PATH=/home/dai-dirk/MetaMapper/MetaMapper/coreir ./clockwork_codegen compile_mem_use_metamapper 1>mem_cout 2> >(tee -a mem_cout >&2); \
EXIT_CODE=$?; rm unoptimized_$1*; cd ..;
#pack
cd ../..
rm ./apps/$1/bin/map_result/$1/design.packed
python3 ./MetaMapper/garnet/garnet.py 1 4 8 ./apps/$1/bin/map_result/$1/$1_to_metamapper.json 1 4 16
# python3 ../MetaMapper/replace.py --packed ../MetaMapper/apps/$1/bin/map_result/$1/design.packed
# #back to PRAD_Framework for PNR
cd ../PRAD_Framework
echo "------------------create new folder:-------------------"
if [ ! -d "./benchmarks/$1/" ];then
    mkdir ./benchmarks/$1/
else
    echo "target file is already exit! "
    rm -r ./benchmarks/$1/*

fi

echo "------------------------run sbt:------------------------"
cd ./Chisel/chisel-PRAD
./chisel.sh
cd ../..
# cp ./test_run_dir/CGRA.v ../../benchmarks/$1


echo "--------------copy IR to traget file:-----------------"
cp ./Chisel/chisel-PRAD/src/main/resources/{1bit.graph,16bit.graph,design.layout,GIB1.json,GIB16.json,cgra_spec.json} ./benchmarks/$1
cp ../MetaMapper/apps/$1/bin/map_result/$1/design.packed ./benchmarks/$1

echo "-----------------generate design.info:-----------------"
if [ -f "./benchmarks/design.info" ];then
    rm -f ./benchmarks/design.info
fi
touch ./benchmarks/design.info
echo "layout="$(realpath ./benchmarks/$1)"/design.layout" > ./benchmarks/design.info
echo "graph=1 "$(realpath ./benchmarks/$1)"/1bit.graph 16 "$(realpath ./benchmarks/$1)"/16bit.graph" >> ./benchmarks/design.info
cp ./benchmarks/design.info ./benchmarks/$1


echo "-----------------------begin PNR:----------------------"
cd ./bs/PNR/cgra_pnr/scripts
# echo "compile:", if need
../install.sh
echo "----------PNR!----------"
PLACER_PATH="/home/dai-dirk/PRAD_Framework/bs/PNR/cgra_pnr/thunder/build/example"
ROUTER_PATH="/home/dai-dirk/PRAD_Framework/bs/PNR/cgra_pnr/cyclone/build/example"
PACKED_FILE="/home/dai-dirk/PRAD_Framework/benchmarks/$1/design.packed"
LAYOUT_FILE="/home/dai-dirk/PRAD_Framework/benchmarks/$1/design.layout"
GRAPH_FILE="1 /home/dai-dirk/PRAD_Framework/benchmarks/$1/1bit.graph 16 /home/dai-dirk/PRAD_Framework/benchmarks/$1/16bit.graph"
PLACEMENT_FILE="/home/dai-dirk/PRAD_Framework/benchmarks/$1/design.place"
ROUTE_FILE="/home/dai-dirk/PRAD_Framework/benchmarks/$1/design.route"
python3 pnr.py --placer-path "${PLACER_PATH}" \
        --router-path "${ROUTER_PATH}" \
        --packed-file "${PACKED_FILE}" \
        --layout-filename "${LAYOUT_FILE}" \
        --graph-path "${GRAPH_FILE}" \
        --placement-filename "${PLACEMENT_FILE}" \
        --route-filename "${ROUTE_FILE}"
# echo "place:"
# ./place.sh ../../../../benchmarks/$1/design.info ../../../../benchmarks/$1/design.packed
# echo "route:"
# ./route.sh ../../../../benchmarks/$1/design.info ../../../../benchmarks/$1/design.packed
echo "--------------------------end--------------------------"

echo "-------------------generate bs files:-------------------"
cd ../../../..
cd ./benchmarks/$1
python3 ../parseroute.py
cd ../..
cp ./benchmarks/$1/{design.place,design.route,GIB1.json,GIB16.json,cgra_spec.json} ./bs/bsGen/input
cp ../MetaMapper/apps/$1/bin/$1_compute_mapped.json ./bs/bsGen/input
cd ./bs/bsGen
python3 ./bitstream.py --mapped-file ./input/$1_compute_mapped.json --track-file ./input/cgra_spec.json
cp ./out/config.bs ../../benchmarks/$1
echo "--------------------------end--------------------------"
cd ../..
