#!/bin/bash

for t in {1..8}; do
    export OMP_NUM_THREADS=$t
    echo "threads: $OMP_NUM_THREADS"
    for i in {400..1000..200}; do
        echo -e "\t$i: $(./prog2 $i)"
    done
done