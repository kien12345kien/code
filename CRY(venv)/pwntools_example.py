from pwn import *  # pip install pwntools
import json
import base64
import codecs
from Crypto.Util.number import bytes_to_long, long_to_bytes

# Connect to the remote server
r = remote('socket.cryptohack.org', 13377, level='debug')

def json_recv():
    line = r.recvline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    r.sendline(request)

def decode_message(enc_type, encoded):
    if enc_type == "base64":
        decoded = base64.b64decode(encoded).decode()
    elif enc_type == "hex":
        decoded = bytes.fromhex(encoded).decode()
    elif enc_type == "rot13":
        decoded = codecs.decode(encoded, 'rot_13')
    elif enc_type == "bigint":
        decoded = long_to_bytes(int(encoded, 16)).decode()
    elif enc_type == "utf-8":
        decoded = ''.join(chr(b) for b in encoded)
    else:
        raise ValueError(f"Unknown encoding type: {enc_type}")
    return decoded

while True:
    received = json_recv()

    print("Received type: ")
    print(received["type"])
    print("Received encoded value: ")
    print(received["encoded"])

    decoded_message = decode_message(received["type"], received["encoded"])
    print("Decoded message: ")
    print(decoded_message)

    to_send = {
        "decoded": decoded_message
    }
    json_send(to_send)

    response = json_recv()
    print("Server response: ")
    print(response)

    if "flag" in response:
        print("Flag: ", response["flag"])
        break
