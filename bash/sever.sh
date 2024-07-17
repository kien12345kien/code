#!/bin/bash

while true; do
    { echo "Bob: $(date)"; cat; } | nc -lk 1234 | while read msg; do echo "$msg"; done
done

