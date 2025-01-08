#!/bin/bash
NAME=constructing_palindromes
if ! [ -f $NAME ]
then
	gcc $NAME.c -o $NAME -Wall -Wvla -lm
fi
chmod +x $NAME
./$NAME
rm -f $NAME
