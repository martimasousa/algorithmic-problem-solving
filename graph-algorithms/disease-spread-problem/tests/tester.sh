#!/bin/bash

# Number of tests to be executed (1-N)
tests=10

# For a better time measurement accuracy you can choose to execute each test N times and the result will be the average execution time 
accuracy=1

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Compile main file
g++ -o ../main ../main.cpp

for ((i=1; i<=$tests; i++)); do
    total_time=0
    for ((it=1; it<=$accuracy; it++)); do
        start_time=$(date +%s%3N)
        ../main < "./test$i.in" > ./out
        end_time=$(date +%s%3N)
        operation_time=$(echo "scale=3; ($end_time - $start_time)" | bc)
        total_time=$(echo "scale=3; ($total_time + $operation_time)" | bc)
    done

    # Calculate the average time
    average_time=$(echo "scale=3; ($total_time / $accuracy) / 1000" | bc)

    # Check if the output is correct (based on each test .out file)
    if diff -q ./out "./test$i.out" > /dev/null; then
        echo -e "${GREEN}Test $i passed ($average_time seconds)${NC}"
    else
        echo -e "${RED}Test $i failed ($average_time seconds)${NC}"
    fi
done

rm -f out
rm -f ../main