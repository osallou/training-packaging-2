#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Check single sequence count
sequence=$srcdir/sequence/raw.seq
(../src/squizz -Sn $sequence 2>&1 | grep -q ' 1 entries') || exit 1
(../src/squizz -Sn -f raw $sequence 2>&1 | grep -q ' 1 entries') || exit 1
(../src/squizz -Sn -c raw -f raw $sequence 2>&1 | grep -q ' 1 entries') || exit 1

## Check single alignment count
sequence=$srcdir/align/msf.seq
(../src/squizz -An $sequence 2>&1 | grep -q ' 1 entries') || exit 1
(../src/squizz -An -f msf $sequence 2>&1 | grep -q ' 1 entries') || exit 1
(../src/squizz -An -c msf -f msf $sequence 2>&1 | grep -q ' 1 entries') || exit 1

## Check single alignment / multiple sequences count
sequence=$srcdir/align/fasta.seq
(../src/squizz -Sn $sequence 2>&1 | grep -q ' 4 entries') || exit 1
(../src/squizz -An $sequence 2>&1 | grep -q ' 1 entries') || exit 1

exit 0
