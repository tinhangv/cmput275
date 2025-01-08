#!/bin/bash
gcc callcentre.cpp -o callcentre  -Wall -Wvla -g -lm && ./callcentre
rm -f ./callcentre
