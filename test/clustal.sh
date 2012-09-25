#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Inits
align=$srcdir/align/clustal.seq

## Check default CLUSTAL file reference
(../src/squizz -A -f clustal $align 2>&1 | grep -v CLUSTAL) && exit 1

## Check without consensus lines
grep -v '^ ' $align >_tmpali.seq
(../src/squizz -A -f clustal _tmpali.seq 2>&1 | grep -v CLUSTAL) && exit 1

## Check without newline at EOF on consensus line
sed -e '$d' $align >_tmpali.seq
tail -n 1 $align | tr -d '\n' >>_tmpali.seq
(../src/squizz -A -f clustal _tmpali.seq 2>&1 | grep -v CLUSTAL) && exit 1

## Check without newline at EOF on sequence line
sed -e '$d' $align | sed -e '$d' >_tmpali.seq
tail -n 2 $align | sed -e '$d' | tr -d '\n' >>_tmpali.seq
(../src/squizz -A -f clustal _tmpali.seq 2>&1 | grep -v CLUSTAL) && exit 1

## Check extra empty line at EOF but without newline
cat $align >_tmpali.seq
echo "   " | tr -d '\n' >>_tmpali.seq
(../src/squizz -A -f clustal _tmpali.seq 2>&1 | grep -v CLUSTAL) && exit 1

## Check without separator after CLUSTAL tag line
echo "CLUSTAL" >_tmpali.seq
tail -n +4 $align >>_tmpali.seq
(../src/squizz -A -f clustal _tmpali.seq 2>&1 | grep CLUSTAL) && exit 1

## Cleanup
rm -f _tmpali.seq

exit 0

