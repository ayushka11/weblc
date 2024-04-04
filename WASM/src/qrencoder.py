import qrcode

with open('/home/darkhood148/Desktop/weblc/WASM/src/test-out.obj', 'rb') as f:
    data = f.read()
    
print(data)
x = int.from_bytes(data, "big")
print(x)
y = str(bin(x)[2:])
print(y)

QRCodefile = "MUOQRCode.png"

QRimage = qrcode.make(y)

QRimage.save(QRCodefile)