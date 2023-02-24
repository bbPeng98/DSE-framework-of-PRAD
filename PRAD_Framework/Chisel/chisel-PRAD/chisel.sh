
sbt "runMain AHA_Interconnect.Instance.garnet -td ./test_run_dir --no-check-comb-loops" -mem 8192

cd ./src/main/resources
echo begin dealing with graph file: 
python3 replace.py
