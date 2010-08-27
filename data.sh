#!/bin/sh

id=$1; shift

for file in {sol,fail}$id-*; do
    export file
    grep 'generation\|time:\|sum=' $file 2>/dev/null \
    | tr '\n' ':' \
    | perl -ne '
    $num = "([ \\d\\.]+)";
    ($user) = /time:.* user $num/;
    ($sys) = /time:.* sys $num/;
    $time = $user + $sys;
    ($gen) = /generation #$num/;
    foreach (split ":") {
        if (($sum) = /sum=$num/) {
            ($var) = /var=$num/;
            ($fit) = /fit.*=$num/;
            print join "\t", $sum, $var, $fit, $time, $gen, "#$ENV{file}";
            print "\n";
        }
    }
    '
done
