#!/usr/bin/env bash

save=$1

case "$save" in
    *.jp?g) fmt=jpeg ext=jpg ;;
    *.eps) fmt="postscript eps color" ext=eps ;;
    *.png|*) fmt=png ext=png ;;
esac

tmp=`mktemp -d /tmp/plotlog.XXXXXX`; export tmp

# reformat data
grep -v '^#' \
| perl -e '
open POPSUM,  ">$ENV{tmp}/popsum";
open POPVAR,   ">$ENV{tmp}/popvar";
open POPFIT,   ">$ENV{tmp}/popfit";
open BESTSUM, ">$ENV{tmp}/bestsum";
open BESTVAR,  ">$ENV{tmp}/bestvar";
open BESTFIT,  ">$ENV{tmp}/bestfit";
sub output {
    my ($out, $value) = @_;
    print $out (join "\t", $gen, $value) . "\n";
}
foreach (<>) {
    $num = "([ \\d\\.-]+)";
    ($gen) = /^$num:/;
    output(POPSUM, /pop[^;]+m=$num/);
    output(POPVAR,  /pop[^;]+v=$num/);
    output(POPFIT,  /pop[^;]+f=$num/);
    output(BESTSUM, /best[^;]+m=$num/);
    output(BESTVAR,  /best[^;]+v=$num/);
    output(BESTFIT,  /best[^;]+f=$num/);
}
open GENS, ">$ENV{tmp}/gens";
print GENS $gen;
'
gens=`cat $tmp/gens`;

plot() {
    type=$1
    out=$tmp/out-$type.$ext
    minx=$2
    maxx=$3
gnuplot >$out <<EOF
reset

set terminal $fmt

set grid x
set grid y

set auto y

set xrange [$minx:$maxx]

#set xtic 50000

set xlabel 'generations'
#set ylabel 'fitness'

set data style linesp

plot '$tmp/popfit'  title 'population fitness', \
'$tmp/popvar'  title 'population variance', \
'$tmp/bestfit' title 'best fitness', \
'$tmp/bestvar' title 'best variance'
#'$tmp/popsum'  title 'population sum', \
#'$tmp/bestsum' title 'best sum'

EOF
if [ -n "$save" ]; then
    cp -f $out "${save%.*}"-$type.$ext
else
    see $out
fi
}

plot init   5 1000
plot all    5 $gens

rm -rf $tmp
