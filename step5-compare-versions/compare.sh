#!/bin/bash

MATRICE_SIZE=500
OMP_NUM_THREADS=1
THIS_SERVER=$(hostname)
PEER_SERVER=$(echo $THIS_SERVER | sed 's/c1/c2/')
echo "Execution on $THIS_SERVER and $PEER_SERVER, size = $MATRICE_SIZE"


binaries=(
    "../step1-sequential/prog1_naive"
    "../step1-sequential/prog2_optimized"
    "../step2-parallelized/prog2_optimized"
    "../step3-multiserver/prog2_optimized_mpi"
    "../step4-multiserver+parallelized/prog2_optimized_mpi_omp"
)
for b in "${binaries[@]}"; do
    if [[ ! -f "$b" || ! -x "$b" ]]; then
        echo "Error: Program $b is missing or not executable."
        exit 1
    fi
done



# Table headers
printf "%-20s %-20s %-20s %-18s\n" "Program version" "Number of Threads" "Number of Servers" "Time"

# STEP 1 = IJK
TIME=$(../step1-sequential/prog1_naive $MATRICE_SIZE | awk '/terminé en/{print $4}')
printf "%-20s %-20s %-20s %-15s\n" "IJK" "$OMP_NUM_THREADS" "1" "$TIME"

# STEP 1 = IKJ
TIME=$(../step1-sequential/prog2_optimized $MATRICE_SIZE | awk '/terminé en/{print $4}')
printf "%-20s %-20s %-20s %-15s\n" "IKJ" "$OMP_NUM_THREADS" "1" "$TIME"

# STEP 2 = OPENMP 2 threads
export OMP_NUM_THREADS=2
TIME=$(../step2-parallelized/prog2_optimized $MATRICE_SIZE | awk '/terminé en/{print $4}')
printf "%-20s %-20s %-20s %-15s\n" "IKJ + OPENMP" "$OMP_NUM_THREADS" "1" "$TIME"

# STEP 2 = OPENMP 4 threads
export OMP_NUM_THREADS=4
TIME=$(../step2-parallelized/prog2_optimized $MATRICE_SIZE | awk '/terminé en/{print $4}')
printf "%-20s %-20s %-20s %-15s\n" "IKJ + OPENMP" "$OMP_NUM_THREADS" "1" "$TIME"



# STEP 3 = MPI
export OMP_NUM_THREADS=1
TIME=$(mpirun -np 2 --host $THIS_SERVER,$PEER_SERVER ../step3-multiserver/prog2_optimized_mpi $MATRICE_SIZE | awk '/finished in/{print $4}')
printf "%-20s %-20s %-20s %-15s\n" "IKJ + MPI" "$OMP_NUM_THREADS" "2" "$TIME"

# STEP 4 = MPI + OPENMP
export OMP_NUM_THREADS=4
TIME=$(OMP_PROC_BIND=spread OMP_PLACES=cores mpirun -np 2 --map-by ppr:1:socket:pe=4 --host $THIS_SERVER,$PEER_SERVER ../step4-multiserver+parallelized/prog2_optimized_mpi_omp $MATRICE_SIZE | awk '/finished in/{print $4}')
printf "%-20s %-20s %-20s %-15s\n" "IKJ + MPI + OPENMP" "$OMP_NUM_THREADS" "2" "$TIME"
