#!/bin/bash
gcc planning_practice.c -o planning_practice -Wall -Wvla -g -lm && ./planning_practice
rm -f ./planning_practice
