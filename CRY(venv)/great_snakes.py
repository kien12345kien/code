#!/usr/bin/env python3

import sys
import base64
# import this

ords = [99, 114, 121, 112, 116, 111, 123, 65, 83, 67, 73, 73, 95, 112, 114, 49, 110, 116, 52, 98, 108, 51, 125]

text = "63727970746f7b596f755f77696c6c5f62655f776f726b696e675f776974685f6865785f737472696e67735f615f6c6f747d"

print("Here is your flag:")
print("".join(chr(o) for o in ords))
# print("".join(chr(o) for o in ords))
print(bytes.fromhex(text))