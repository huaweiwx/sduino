#!/bin/bash

## parameter check

if [ $# -ne 1 ]; then
	cat << EOF
split the library into individual source files for every single function,
compile them seperately and pack them all together into one big library.

usage: $0 cputype

supported cpu types:
	STM8L15X_HD
	LSTM8L15X_MDP
	STM8L15X_MD
	STM8L15X_LD
EOF
	exit 1
fi

CPU=$1


### main part starts here


# define the compile parameter
CC="sdcc"
AR="sdar"
CFLAGS="-mstm8 -D${CPU} -I ../inc -I ../src --opt-code-size -I."
LDFLAGS="-rc"

BUILDDIR="build-${CPU}"



# name of the library: $CPU.lib in lower case
LIBRARY=$(echo ${CPU}|tr '[:upper:]' '[:lower:]').lib

# check the dependencies, generate the list of needed c source files
HFILES=$($CC -mstm8 -Iinc -Isrc -D$CPU "-Wp-MM" -E inc/stm8l15x.h|fmt -1|sed -n 's, *inc/stm8l15x_,stm8l15x_,p')
CFILES=${HFILES//.h/.c}

# debug output
echo "Needed source code modules for CPU $CPU:"
echo $CFILES
echo "Library name: $LIBRARY"
echo "cflags: $CFLAGS"


# the most important function: split on c source file in to a collection
# of single-function source files.
splitit() {
    awk "/\/\*\*\r/{n++; file=\"$1-\" n \".c\";print \"#include \\\"$1.h\\\"\">file}{print >file }" ../src/$1
    sed "1 d" $1-1.c > $1.h
    rm $1-1.c
}


# prepare a fresh build directory
#BUILDDIR=$(mktemp -dp.)
rm -rf $BUILDDIR
mkdir $BUILDDIR
cd $BUILDDIR
echo "using $BUILDDIR"

# split all needed source files into single-function source files
for i in $CFILES; do
	splitit $i;
done

# compile all split files
#cp ../compilelib.mk Makefile
#make CPU=$CPU
for i in stm8l15x_*.c; do
	echo "compiling $i"
	${CC} ${CFLAGS} -c $i || break
done

# build the library
${AR} ${LDFLAGS} ../lib/${LIBRARY} *.rel

# get the generated library
#mv *.lib ..
