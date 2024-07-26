# Given string label
label = "label"

# Initialize an empty list to collect XORed characters
xored_chars = []

# XOR each character with 13
for char in label:
    # Convert character to Unicode integer
    unicode_int = ord(char)
    # XOR with 13
    xored_int = unicode_int ^ 13
    # Convert back to character
    xored_char = chr(xored_int)
    # Append to list
    xored_chars.append(xored_char)

# Join the list into a new string
new_string = ''.join(xored_chars)

# Format the result as required
flag = f"crypto{{{new_string}}}"

# Print the flag
print(flag)
