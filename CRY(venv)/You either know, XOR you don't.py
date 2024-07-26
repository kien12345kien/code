encrypt_msg = "0e0b213f26041e480b26217f27342e175d0e070a3c5b103e2526217f27342e175d0e077e263451150104"
encrypt_msg = bytes.fromhex(encrypt_msg)

flag_format = b"crypto{"

key = [o1 ^ o2 for (o1, o2) in zip (encrypt_msg, flag_format)] + [ord("y")]

flag = []
key_len = len(key)
for i in range(len(encrypt_msg)):
    flag.append(
        encrypt_msg[i] ^ key[i % key_len]
    )
flag = "".join(chr(o) for o in flag)

print("Flag: ")
print(flag)