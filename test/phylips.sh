#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Inits
align=$srcdir/align/phylips.seq

## Check default PHYLIPS file reference
(../src/squizz -A -f phylips $align 2>&1 | grep -v PHYLIPS) && exit 1

## Check for sequences on a single line (= PHYLIPI)
grep -v '^$' $align | grep -v '^          ' >_tmpali.seq
(../src/squizz -A -f phylips _tmpali.seq 2>&1 | grep -v PHYLIPS) && exit 1

## Check with empty line after header
echo " 13 109" >_tmpali.seq
echo >>_tmpali.seq
tail -n +2 $align >>_tmpali.seq
(../src/squizz -A -f phylips _tmpali.seq 2>&1 | grep PHYLIPS) && exit 1

## Check sequence names with spaces
sed 's,\., ,' $align >_tmpali.seq
(../src/squizz -A -f phylips _tmpali.seq 2>&1 | grep -v PHYLIPS) && exit 1

## Check without newline at EOF
sed -e '$d' $align >_tmpali.seq
tail -n 1 $align | tr -d '\n' >>_tmpali.seq
(../src/squizz -A -f phylips _tmpali.seq 2>&1 | grep -v PHYLIPS) && exit 1

## Cleanup
rm -f _tmpali.seq

exit 0

