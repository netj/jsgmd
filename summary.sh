#!/usr/bin/env bash

id=$1; shift

N=$id perl -e '
$N = $ENV{N};
sub sum {
    my $s = shift;
    $s += $_ foreach @_;
    $s
}
sub avg { sum(@_) / @_ }
sub max {
    my $m = shift;
    foreach (@_) {
        $m = $_ if $_ > $m;
    }
    $m
}

$cnt = 0;
while ($line = <>) {
    @data = split "\t", $line;
    $sum = $data[0];
    $var = $data[1];
    $gen = $data[4];
    $time = $data[3];

    $fit = $sum - sqrt($var * $N);

    push @fits, $fit;
    push @times, $time;
    push @gens, $gen;
    $cnt++;
}
print join "\t", $cnt,
    (map {sprintf "%7.5f", $_} avg(@fits), max(@fits)),
    (map {sprintf "%4.2f", $_} avg(@times), avg(@gens));
print "\n";
'
