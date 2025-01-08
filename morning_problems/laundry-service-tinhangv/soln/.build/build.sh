#!/bin/bash
NAME=laundry_service
if ! [ -f $NAME ]
then
    g++ $NAME.cc -o $NAME -Wall -std=c++11
fi
chmod +x $NAME
./$NAME
rm -f $NAME
