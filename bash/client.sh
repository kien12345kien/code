#!/bin/bash

SERVER_IP="192.168.1.21"
PORT=1234
CLIENT_NAME="Alice"

while true; do
    { echo "$CLIENT_NAME: $(date)"; cat; } | nc $SERVER_IP $PORT | while read msg; do echo "$msg"; done
done
