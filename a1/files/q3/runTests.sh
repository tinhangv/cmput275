#!/bin/bash

for stem in $(cat $2); do
    #redirect input from stem.in and run command with stem.args and
    #compare output to stem.out

    temp=$(mktemp)
    $1 $(cat $stem.args) < $stem.in > $temp
    diff $temp $stem.out > /dev/null

    #no difference: output "Test stem passed"
    if [ $? -eq 0 ]; then
        echo Test $stem passed
    else
    #difference: output "Test stem failed", "Expected ouput:", 
    #contents of stem.out, "Actual output:", output produced
        echo Test $stem failed
        echo Expected output:
        cat $stem.out
        echo Actual output:
        cat $temp
    fi
done