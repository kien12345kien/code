#!/bin/bash

#checks whether the number of arguments passed to the script is not equal to 1
if [ $# -ne 1 ]; then
    echo "Usage: $0 <integer>"
    exit 1
fi

val=$1

# integer condition
if ! [[ "$val" =~ ^-?[0-9]+$ ]]; then
    echo "not integer!"
    exit 1
fi

#multiply result
output=$(( val * 2 ))
echo $output
