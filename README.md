## PRAD
## PRAD:A Bayesian Optimization-based DSE Framework for Parameterized Reconfigurable Architecture Design


#### MetaMapper: is used to map DFG to mapped DFG

#### PRAD_Framework: includes PRAD hardware modeling, DSE flow, etc.
    |benchmarks: test cases
    |Chisel: chisel-based PRAD hardware modeling
        |chisel-PRAD/src/main/scala/ppa: rapid area evaluation model
        |chisel-PRAD/src/main/scala/PRAD: hardware modeling code
    |dse: design space exploration
        |hebo: code of Bayesian optimization-based DSE
    |flow.sh: the execution script for the overall framework
