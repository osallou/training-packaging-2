#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Inits
alifmt='CLUSTAL FASTA MSF NEXUS PHYLIPI PHYLIPS STOCKHOLM'

## Check sequences names with spaces
sed 's/\./ /' $srcdir/align/phylips.seq >_tmpali.seq
for f in $alifmt; do
  ../src/squizz -c $f _tmpali.seq >_tmpali2.seq 2>/dev/null || exit 1
  (../src/squizz _tmpali2.seq 2>&1 | grep -v $f) && exit 1
done

## Check for unexpected sequence name
sed -e '$d' $srcdir/align/clustal.seq | sed -e '$d' >_tmpali.seq
tail -n 2 $srcdir/align/clustal.seq | sed 's/_/-/' >>_tmpali.seq
(../src/squizz -A _tmpali.seq 2>&1 | grep -v UNKNOWN) && exit 1

## Check for duplicate sequence name
cat $srcdir/align/fasta.seq $srcdir/align/fasta.seq >_tmpali.seq
(../src/squizz -A _tmpali.seq 2>&1 | grep -v UNKNOWN) && exit 1

## Cleanup
rm -f _tmpali*.seq

exit 0

