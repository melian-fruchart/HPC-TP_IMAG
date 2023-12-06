#!/bin/bash

# Print header
printf "%-18s\t%-20s\t%-20s\n" "Nombre de threads" "Taille de la matrice" "Temps prog2_optimized (s)"

# Array of number of threads
threads=$(seq 1 1 8)

# Array of matrix sizes
sizes=$(seq 200 200 1000)

for t in $threads; do
    export OMP_NUM_THREADS=$t
    for i in $sizes; do
        result=$(./prog2_optimized $i)
        time=$(echo $result | awk '{print $(NF)}')  # Assuming the second last word is the time
        printf "%-18s\t%-20s\t%-20s\n" "${t}" "${i}*${i}" "$time"
    done
    printf "\n"
done