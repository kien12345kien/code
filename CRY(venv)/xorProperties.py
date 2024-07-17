# Provided hex values
key1 = bytes.fromhex("a6c8b6733c9b22de7bc0253266a3867df55acde8635e19c73313")
key2xkey1 = bytes.fromhex("37dcb292030faa90d07eec17e3b1c6d8daf94c35d4c9191a5e1e")
key2xkey3 = bytes.fromhex("c1545756687e7573db23aa1c3452a098b71a7fbf0fddddde5fc1")
FLAGxk1xk2xk3 = bytes.fromhex("04ee9855208a2cd59091d04767ae47963170d1660df7f56f5faf")

# Calculating key2 without using zip()
key2 = bytes([key2xkey1[i] ^ key1[i] for i in range(len(key1))])

# Calculating key3 without using zip()
key3 = bytes([key2xkey3[i] ^ key2[i] for i in range(len(key2))])

# Calculating FLAG without using zip()
FLAG = bytes([FLAGxk1xk2xk3[i] ^ key1[i] ^ key2[i] ^ key3[i] for i in range(len(FLAGxk1xk2xk3))])

print(FLAG.decode())


# # Define the hex strings
# KEY1 = "a6c8b6733c9b22de7bc0253266a3867df55acde8635e19c73313"
# KEY2_XOR_KEY1 = "37dcb292030faa90d07eec17e3b1c6d8daf94c35d4c9191a5e1e"
# KEY2_XOR_KEY3 = "c1545756687e7573db23aa1c3452a098b71a7fbf0fddddde5fc1"
# FLAG_XOR_KEYS = "04ee9855208a2cd59091d04767ae47963170d1660df7f56f5faf"

# # Convert hex strings to byte arrays
# KEY1_bytes = bytes.fromhex(KEY1)
# KEY2_XOR_KEY1_bytes = bytes.fromhex(KEY2_XOR_KEY1)
# KEY2_XOR_KEY3_bytes = bytes.fromhex(KEY2_XOR_KEY3)
# FLAG_XOR_KEYS_bytes = bytes.fromhex(FLAG_XOR_KEYS)

# # XOR function
# def xor_bytes(a, b):
#     return bytes(x ^ y for x, y in zip(a, b))

# # Calculate KEY2
# KEY2_bytes = xor_bytes(KEY1_bytes, KEY2_XOR_KEY1_bytes)

# # Calculate KEY3
# KEY3_bytes = xor_bytes(KEY2_bytes, KEY2_XOR_KEY3_bytes)

# # Calculate FLAG
# FLAG_bytes = xor_bytes(FLAG_XOR_KEYS_bytes, xor_bytes(KEY1_bytes, xor_bytes(KEY2_bytes, KEY3_bytes)))

# # Convert the result to hex
# KEY2 = KEY2_bytes.hex()
# KEY3 = KEY3_bytes.hex()
# FLAG = FLAG_bytes.hex()

# KEY2, KEY3, FLAG
