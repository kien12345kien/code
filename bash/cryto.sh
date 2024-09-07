#!/bin/bash

# Replace with the actual API endpoint and parameters
API_URL="https://www.okx.com/api/v5/market/ticker?instId=BTC-USDT"

# Loop indefinitely
while true; do
    # Fetch data from the OKX API
    response=$(curl -s $API_URL)
    
    # Parse the response to extract the desired ratio data (modify based on the actual response format)
    ratio=$(echo $response | jq -r '.data[0].last')
    
    # Display the ratio
    echo "BTC Ratio: $ratio"
    
    # Wait for 1 second before the next iteration
    sleep 1
done
