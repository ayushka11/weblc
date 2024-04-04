from pyzbar.pyzbar import decode
from PIL import Image
decocdeQR = decode(Image.open('/home/darkhood148/Desktop/weblc/WASM/src/MUOQRCode.png'))
print(decocdeQR[0].data.decode('ascii'))