#!/bin/bash
g++ missing_multipliers.cc -o missing_multipliers -Wall -std=c++11 -g && ./missing_multipliers
rm -f ./missing_multipliers
