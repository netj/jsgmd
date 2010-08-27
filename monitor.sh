#!/bin/sh

while true; do
    echo
    for i in 24 54 80 110 224; do
        echo -n "$i=`ls sol$i*.out | wc -l`/`ls {fail,sol}$i*.out | wc -l` "
    done 2>/dev/null
    sleep ${1:-10}
done
