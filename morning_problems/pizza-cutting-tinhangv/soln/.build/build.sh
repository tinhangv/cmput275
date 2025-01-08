#!/bin/bash
NAME=pizza_cutting
if ! [ -f $NAME ]
then
	gcc $NAME.c -o $NAME -Wall -Wvla
fi
chmod +x $NAME
./$NAME
rm -f $NAME
