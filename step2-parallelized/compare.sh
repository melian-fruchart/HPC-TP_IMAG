#!/bin/bash

# The number of threads can be passed as an argument 
if [[ "$#" -gt 0 && $1 -gt 0 ]]; then
        export OMP_NUM_THREADS=$1
else
        export OMP_NUM_THREADS=1
fi

# Print number of threads
echo "Running '$(basename $0)' on $OMP_NUM_THREADS thread(s)."

# Print header
printf "%-18s\t%-20s\t%-20s\n" "Taille de la matrice" "Temps prog1_naive (s)" "Temps prog2_optimized (s)"

# Array of matrix sizes
sizes=$(seq 500 500 1500)

for i in $sizes; do
    result1=$(./prog1_naive $i)
    result2=$(./prog2_optimized $i)
    time1=$(echo $result1 | awk '{print $(NF)}')  # Assuming the second last word is the time
    time2=$(echo $result2 | awk '{print $(NF)}')  # Assuming the second last word is the time
    printf "%-18s\t%-20s\t%-20s\n" "${i}*${i}" "$time1" "$time2"
done