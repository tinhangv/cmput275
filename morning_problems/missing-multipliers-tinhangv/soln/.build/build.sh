#!/bin/bash
NAME=missing_multipliers
if ! [ -f $NAME ]
then
	g++ $NAME.cc -o $NAME -Wall -std=c++11 -g
fi
chmod +x $NAME
./$NAME
rm -f $NAME
