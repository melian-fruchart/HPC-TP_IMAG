#!/bin/bash

# Print header
printf "%-18s\t%-20s\t%-20s\n" "Taille de la matrice" "Temps prog1_naive (s)" "Temps prog2_optimized (s)"

# Array of matrix sizes
sizes=$(seq 100 100 1500)

# Loop through sizes and print formatted output
for i in "${sizes[@]}"; do
    result1=$(./prog1_naive $i)
    result2=$(./prog2_optimized $i)
    time1=$(echo $result1 | awk '{print $(NF)}')  # Assuming the second last word is the time
    time2=$(echo $result2 | awk '{print $(NF)}')  # Assuming the second last word is the time
    printf "%-18s\t%-20s\t%-20s\n" "${i}*${i}" "$time1" "$time2"
done
