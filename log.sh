#!/usr/bin/env bash

interval=0.5
id=$1; shift
exe=./jsgmd-$id

if [ -x $exe ]; then
    tmp=`mktemp -d /tmp/jsgmd.XXXXXX`
    set -m +b

    # run in background
    "$exe" 2>$tmp/log >$tmp/out &
    pid=$!

    # send signals
    (
    sleep $interval
    while kill -INT $pid 2>/dev/null; do
        sleep $interval
        echo -n .
    done
    ) &

    # wait in foreground
    if fg -; then
        t=`date +%Y%m%dT%H%M%S%N`
        log=log$id-$t.out
        out=sol$id-$t.out
        cp $tmp/log $log
        cp $tmp/out $out
    else
        t=`date +%Y%m%dT%H%M%S%N`
        log=log$id-$t.out
        out=fail$id-$t.out
        cp $tmp/log $log
        cp $tmp/out $out
    fi
    rm -rf $tmp
else
    echo "$exe: No such file" >&2
fi
