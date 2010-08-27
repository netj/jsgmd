#!/bin/sh
N=$1; shift

for ((i=0; i<$N; i++)); do
    ./run.sh "$@"
done
