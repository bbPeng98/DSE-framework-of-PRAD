#!/bin/bash
echo "------------------ map and pack --------------------"
#generate rewrite-rules
python3 ./MetaMapper/src/lassen/scripts/my_regenerate_peak_rules.py $2
#map pe
python3 ./MetaMapper/scripts/map_app.py ./apps/$1/bin/$1_compute.json 0 $2
#map mem
cd ./apps/$1/bin
sed -i -e 's/_mapped//g' ./$1_compute_mapped.json
CLKWRK_PATH=/home/dai-dirk/MetaMapper/MetaMapper/clockwork LD_LIBRARY_PATH=/home/dai-dirk/MetaMapper/MetaMapper/clockwork/lib:/home/dai-dirk/MetaMapper/MetaMapper/coreir/lib LAKE_PATH=/home/dai-dirk/MetaMapper/MetaMapper/src/lake-aha LAKE_CONTROLLERS=/home/dai-dirk/MetaMapper/MetaMapper/test/bin LAKE_STREAM=./bin COREIR_PATH=/home/dai-dirk/MetaMapper/MetaMapper/coreir ./clockwork_codegen compile_mem_use_metamapper 1>mem_cout 2> >(tee -a mem_cout >&2); \
EXIT_CODE=$?; rm unoptimized_$1*; cd ..;
#pack
cd ../..
python3 ./MetaMapper/garnet/garnet.py $2 1 4 8 ./apps/$1/bin/map_result/$1/$1_to_metamapper.json 1 4 16
#back to AHA_GIB for PNR
cd ../AHA_GIB

echo "------------------create new folder:-------------------"
if [ ! -d "./benchmarks/$1/" ];then
    mkdir ./benchmarks/$1/
else
    echo "target file is already exit! "
    # rm -r ./benchmarks/$1/*

fi

echo "------------------------run sbt:------------------------"
cd ./Chisel/chisel-AHA6.0
./chisel.sh
# cp ./test_run_dir/CGRA.v ../../benchmarks/$1


echo "--------------remove IR to traget file:-----------------"
cp ./Chisel/chisel-AHA6.0/src/main/resources/{1bit.graph,16bit.graph,design.layout,GIB1.json,GIB16.json} ./benchmarks/$1


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
echo "compile:"
../install.sh
echo "place:"
./place.sh ../../../../benchmarks/$1/design.info ../../../../benchmarks/$1/design.packed
echo "route:"
./route.sh ../../../../benchmarks/$1/design.info ../../../../benchmarks/$1/design.packed
echo "--------------------------end--------------------------"

echo "-------------------generate bs files:-------------------"
cd ../../../..
cd ./benchmarks/$1
python3 ../parseroute.py
cd ../..
cp ./benchmarks/$1/{design.place,design.route,GIB1.json,GIB16.json} ./bs/bsGen/input
cp ../MetaMapper/apps/bin/$1_compute_mapped.json ./bs/bsGen/input
cd ./bs/bsGen
python3 ./bitstream.py
echo "--------------------------end--------------------------"
cd ../..
