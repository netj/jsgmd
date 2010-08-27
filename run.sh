#!/bin/sh

id=$1
exe=./jsgmd$id
if [ -x $exe ]; then
    tmp=`mktemp /tmp/jsgmd.XXXXXX`
    if "$exe" >$tmp; then
        new=sol$id-`date +%Y%m%dT%H%M%S%N`.out
        cp $tmp $new
    else
        new=fail$id-`date +%Y%m%dT%H%M%S%N`.out
        cp $tmp $new
    fi
    cat $new
    echo at $new
    rm -f $tmp
else
    echo "$exe: No such file" >&2
fi
