#!/bin/bash

for i in {100..1500..200}; do
    echo "$i: $(./prog1 $i)"
    echo "$i: $(./prog2 $i)"
done