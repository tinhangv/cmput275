#!/bin/bash

cd $1
for x in *.zip; do
    echo $1/$x
done

