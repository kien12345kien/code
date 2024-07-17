#!/bin/bash

# 0. check 8.8.8.8
echo "Pinging 8.8.8.8..."
ping -c 4 8.8.8.8

# Fetching HTML
echo "Fetching HTML page of www.gnu.org..."
curl www.gnu.org

# Function to search a web page for a search string
search_webpage() {
    local url=$1
    local search_string=$2
    curl -s "$url" | grep -i "$search_string"
}
# Example usage of the function
# echo "Searching for 'GNU' in www.gnu.org..."
# search_webpage "http://www.gnu.org" "GNU"

# 1. Look up the IP of www.gnu.org using dig
echo "Looking up IP of www.gnu.org using dig..."
dig www.gnu.org

# 2. Look up the IP of www.gnu.org using host
echo "Looking up IP of www.gnu.org using host..."
host www.gnu.org

# 3. Look up the IP of www.gnu.org using nslookup
echo "Looking up IP of www.gnu.org using nslookup..."
nslookup www.gnu.org

# 4. Look up the IP using dig with a specific DNS (8.8.4.4)
echo "Looking up IP of www.gnu.org using dig with DNS 8.8.4.4..."
dig @8.8.4.4 www.gnu.org

# 5. Silently look up the IP using dig with a specific DNS and minimal output
echo "Silently looking up IP of www.gnu.org using dig with DNS 8.8.4.4 and minimal output..."
dig @8.8.4.4 www.gnu.org +short
