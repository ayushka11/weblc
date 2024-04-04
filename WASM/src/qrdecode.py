x="110000000000000010000000000010111100000010000111110000001001010000000001000001"
w=int(x,2)
print(w)
x_bytes = w.to_bytes((w.bit_length() + 7) // 8, 'big')
print(x_bytes)
with open("output.obj", "wb") as f:
    f.write(x_bytes)