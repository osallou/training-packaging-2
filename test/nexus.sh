#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Inits
align=$srcdir/align/nexusi.seq

## Check default NEXUS file reference
(../src/squizz -A -f nexus $align 2>&1 | grep -v NEXUS) && exit 1

## Check `token = value' commands (with extra spaces)
sed 's/=/ = /g' $align >_tmpali.seq
(../src/squizz -A -f nexus _tmpali.seq 2>&1 | grep -v NEXUS) && exit 1

## Check sequence name with spaces/brackets
sed "s/^Sp2-Hs  /'Sp2 Hs'/" $align >_tmpali.seq
(../src/squizz -A -f nexus _tmpali.seq 2>&1 | grep -v NEXUS) && exit 1
sed "s/^Sp2-Hs  /'Sp2[x]'/" $align >_tmpali.seq
(../src/squizz -A -f nexus _tmpali.seq 2>&1 | grep -v NEXUS) && exit 1

## Check end tag in ignored block
cat $align >_tmpali.seq
printf "\nbegin dummy\n  append;\nend;\n" >>_tmpali.seq
(../src/squizz -A -f nexus _tmpali.seq 2>&1 | grep -v NEXUS) && exit 1

## Cleanup
rm -f _tmpali.seq

exit 0

