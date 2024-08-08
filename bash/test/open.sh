#!/bin/bash

echo "File Name"

read varname

if [ -File "$varname" ]; then
    open "$varname

else
    echo "file not found"

fi