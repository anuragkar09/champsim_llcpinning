#!/usr/bin/env python

import os
import sys
import time
import shutil
from multiprocessing import Pool

test_base_dir = "/trace2/ChampSim/dpc3"
       
## This is only SPEC CPU 2006 for now
'''
tests=["400.perlbench-50B.champsimtrace.xz",
       "401.bzip2-226B.champsimtrace.xz",
       "403.gcc-48B.champsimtrace.xz",
       "410.bwaves-1963B.champsimtrace.xz", "416.gamess-875B.champsimtrace.xz","429.mcf-184B.champsimtrace.xz","433.milc-337B.champsimtrace.xz","434.zeusmp-10B.champsimtrace.xz","435.gromacs-228B.champsimtrace.xz",
        "436.cactusADM-1804B.champsimtrace.xz","437.leslie3d-273B.champsimtrace.xz","444.namd-426B.champsimtrace.xz","445.gobmk-36B.champsimtrace.xz","447.dealII-3B.champsimtrace.xz",
        "450.soplex-247B.champsimtrace.xz","453.povray-887B.champsimtrace.xz","454.calculix-460B.champsimtrace.xz","456.hmmer-327B.champsimtrace.xz","458.sjeng-1088B.champsimtrace.xz",
        "459.GemsFDTD-1418B.champsimtrace.xz","462.libquantum-1343B.champsimtrace.xz","464.h264ref-97B.champsimtrace.xz","465.tonto-1914B.champsimtrace.xz","470.lbm-1274B.champsimtrace.xz",
        "471.omnetpp-188B.champsimtrace.xz","473.astar-359B.champsimtrace.xz","481.wrf-1281B.champsimtrace.xz","482.sphinx3-1522B.champsimtrace.xz","483.xalancbmk-736B.champsimtrace.xz"]
'''

tests = ["602.gcc_s-1850B.champsimtrace.xz", "603.bwaves_s-2931B.champsimtrace.xz", "605.mcf_s-994B.champsimtrace.xz", "607.cactuBSSN_s-2421B.champsimtrace.xz",
         "620.omnetpp_s-141B.champsimtrace.xz", "621.wrf_s-6673B.champsimtrace.xz", "623.xalancbmk_s-592B.champsimtrace.xz", "628.pop2_s-17B.champsimtrace.xz",
          "649.fotonik3d_s-10881B.champsimtrace.xz", "654.roms_s-1007B.champsimtrace.xz" ]

def launch_test(name, warmup, cycles, output_dir, binary):
    print("Launching test: " + name)
    print("Warmup: " + str(warmup))
    print("Cycles: " + str(cycles))
    print("Test complete: " + name)
    print("Output directory: " + output_dir)
    os.makedirs(output_dir, exist_ok=True)  # Create the output directory if it doesn't exist
    shutil.copy(binary, output_dir)  # Copy the binary to the output directory
    print("Output directory created: " + output_dir)
    test_dir = os.path.join(output_dir, name)  # Create a subdirectory for the test
    os.makedirs(test_dir, exist_ok=True)  # Create the test directory if it doesn't exist
    os.chdir(test_dir)  # Change to the test directory)
    print("Generating output files...")
    command=[]
    command.append("nohup")
    command.append(binary)
    command.append("--warmup_instructions "+str(warmup))
    command.append("--simulation_instructions "+str(cycles))
    command.append("-traces "+test_base_dir+"/"+name)
    
    # added to simulate multi cores 
    print("Core count: " , int(cores))
    for i in range(cores):
        command.append(test_base_dir+"/"+name)
    
    command.append("&")
    print(" ".join(command))
    os.system(" ".join(command))


if __name__ == "__main__":
    output_dir = sys.argv[1]
    output_dir = os.path.abspath(output_dir)
    binary = sys.argv[2]
    binary = os.path.abspath(binary)
    warmup = int(sys.argv[3])
    cycles = int(sys.argv[4])
    cores = int(sys.argv[5])
    
    total_cores = os.cpu_count()
    cores_to_use = max(1, total_cores // 2)

    # Prepare the arguments for each test
    args = [(test, warmup, cycles, output_dir, binary, cores) for test in tests]
    # Use a process pool to manage concurrent test execution
    with Pool(processes=cores_to_use) as pool:
        pool.map(launch_test, args)