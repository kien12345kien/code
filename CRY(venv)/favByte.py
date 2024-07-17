hex_string = "0e0b213f26041e480b26217f27342e175d0e070a3c5b103e2526217f27342e175d0e077e263451150104"

# Convert hex string to bytes
encoded_bytes = bytes.fromhex(hex_string)

size_of_encoded_bytes = len(encoded_bytes)

# Iterate over each possible key (0x00 to 0xFF)
for key in range(20):
    decrypted_message = []
    # XOR each byte of encoded_bytes with the current key
    for byte in encoded_bytes:
        decrypted_byte = byte ^ key
        decrypted_message.append(decrypted_byte)
    
    # Convert decrypted bytes to a string
    decrypted_string = ''.join(chr(byte) for byte in decrypted_message)
    
    # Print the key and decrypted string
    print(f"Key: 0x{key:02X}, Decrypted message: {decrypted_string}")
