#!/bin/bash

string="this is a string"

# Initialize an empty string to collect the first letters
first_letters=""

for word in $string; do
    # Get the first letter of the current word
    n="${word:0:1}"
    # Append the first letter to the first_letters string
    first_letters+="$n"
done

# Print the collected first letters
echo "$first_letters"

