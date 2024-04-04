import qrcode

with open('ok-out.obj', 'rb') as f:
    data = f.read()
    
print(data)
x = int.from_bytes(data, "big")
print(x)
x_bytes = x.to_bytes((x.bit_length() + 7) // 8, 'big')
print(x_bytes)
y = str(bin(x)[2:])
print(pow(2,78))
QRCodefile = "MUOQRCode.png"

QRimage = qrcode.make(y)

QRimage.save(QRCodefile)