#!/bin/bash
# You may use this file to test manually for bug fixes/sample cases.
gcc pizza_cutting.c -o pizza_cutting -lm -Wall -Wvla -g && ./pizza_cutting
rm -f ./pizza_cutting
