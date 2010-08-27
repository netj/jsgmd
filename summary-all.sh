#!/bin/sh

t=`date +%Y%m%d`

# header
for i in N \#runs mean_fit max_fit time \#gens; do
    echo -en "$i\t"
done
echo

# each summary
for i in 24 54 80 110 224; do
    echo -en "$i\t"
    dump=doc/exp$i-$t.txt
    [ -e "$dump" ] || ./data.sh $i >$dump
    ./summary.sh $i <$dump
done
