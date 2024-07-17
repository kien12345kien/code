from pwn import *  # pip install pwntools
import json
import base64
import codecs
from Crypto.Util.number import bytes_to_long, long_to_bytes

def json_recv():
    line = r.recvline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    r.sendline(request)

def decode_message(encoded_type, encoded_value):
    if encoded_type == "base64":
        return base64.b64decode(encoded_value).decode()
    elif encoded_type == "hex":
        return bytes.fromhex(encoded_value).decode()
    elif encoded_type == "rot13":
        return codecs.decode(encoded_value, 'rot_13')
    elif encoded_type == "bigint":
        return long_to_bytes(int(encoded_value, 16)).decode()
    elif encoded_type == "utf-8":
        return ''.join(chr(i) for i in encoded_value)
    else:
        raise ValueError(f"Unknown encoding type: {encoded_type}")

# Connect to the remote service
r = remote('socket.cryptohack.org', 13377, level='debug')

# Initial message
received = json_recv()
print("Received type: ")
print(received["type"])
print("Received encoded value: ")
print(received["encoded"])

# Decode the received message
decoded_value = decode_message(received["type"], received["encoded"])

# Send the decoded message
to_send = {
    "decoded": decoded_value
}
json_send(to_send)

# Receive the response
response = json_recv()
print("Response: ", response)

# Close the connection
r.close()
