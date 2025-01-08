#!/bin/bash
gcc constructing_palindromes.c -o constructing_palindromes -Wall -Wvla -g -lm && ./constructing_palindromes
rm -f ./constructing_palindromes
