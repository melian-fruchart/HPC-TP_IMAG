#!/bin/bash

export OMP_NUM_THREADS=1
echo "threads: $OMP_NUM_THREADS"
for i in {500..1500..500}; do
    echo -e "\t$i: $(./prog1 $i)"
    echo -e "\t$i: $(./prog2 $i)"
done