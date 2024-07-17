import base64

# Original string
original_string = "Base+64+Encoding+is+Web+Safe"

# Encoding to Base64
encoded_bytes = base64.b64encode(original_string.encode("utf-8"))
encoded_string = encoded_bytes.decode("utf-8")

print(encoded_string)
