#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Inits
align=$srcdir/align/mega.seq

## Check default MEGA file reference
(../src/squizz -A -f mega $align 2>&1 | grep -v MEGA) && exit 1

## Check without newline at EOF
sed -e '$d' $align >_tmpali.seq
tail -n 1 $align | tr -d '\n' >>_tmpali.seq
(../src/squizz -A -f mega _tmpali.seq 2>&1 | grep -v MEGA) && exit 1

## Check old style statements
sed 's,^!Title,Title:,' $align | grep -v '^!' >_tmpali.seq
(../src/squizz -A -f mega _tmpali.seq 2>&1 | grep -v MEGA) && exit 1

## Check for "identical" character in sequences
sed -e 's/-/./g' $align >_tmpali.seq
(../src/squizz -A -f mega _tmpali.seq 2>&1 | grep -v MEGA) && exit 1

## Check for comment/description after sequence name
sed -e 's/^#MALK_.*$/& "this is a description"/' $align >_tmpali.seq
(../src/squizz -A -f mega _tmpali.seq 2>&1 | grep -v MEGA) && exit 1
sed -e 's/^#MALK_.*$/& [this is a comment]/' $align >_tmpali.seq
(../src/squizz -A -f mega _tmpali.seq 2>&1 | grep -v MEGA) && exit 1

## Check for very long names
ext='this_is_an_extension_with_more_many_many_characters_for_long_names'
sed -e "s/^#MALK_.*$/&_${ext}/" $align >_tmpali.seq
(../src/squizz -A -f mega _tmpali.seq 2>&1 | grep -v MEGA) && exit 1

## Do not choke if sequence name starts with mega string
sed -e "s/^#MALK_SALTY/#MEGA_SALTY/" $align >_tmpali.seq
(../src/squizz -A -f mega _tmpali.seq 2>&1 | grep -v MEGA) && exit 1

## Cleanup
rm -f _tmpali.seq

exit 0

