#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Inits
sequence=$srcdir/sequence/embl.seq

## Check default EMBL file reference
(../src/squizz -S -f embl $sequence 2>&1 | grep -v EMBL) && exit 1

## Check anonymous sequence
head -n +1 $sequence | sed 's/X97897/      /' >_tmpseq.seq
tail -n +2 $sequence >>_tmpseq.seq
../src/squizz -S -f embl _tmpseq.seq >/dev/null 2>&1 || exit 1
(../src/squizz -S -f embl _tmpseq.seq 2>&1 | grep EMBL) && exit 1

## Check for keyword with internal `;'
sed 's,vasodilator-stimulated,vasodilator;stimulated,' $sequence >_tmpseq.seq
(../src/squizz -S -f embl _tmpseq.seq 2>&1 | grep -v EMBL) && exit 1

## Cleanup
rm -f _tmpseq.seq

exit 0

