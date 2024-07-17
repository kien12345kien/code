#!/bin/bash

search_webpage() {
    local url=$1
    local search_string=$2
    
    # Fetch the webpage content
    local content=$(curl -s "$url")
    
    # Search for the string
    echo "$content" | grep -o "$search_string"
}

search_webpage "http://www.gnu.org" "GNU"

