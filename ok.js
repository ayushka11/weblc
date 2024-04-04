const fs = require('fs');

const x = "110000000000000010000000000010111100000010000111110000001001010000000001000001";

const byteLength = Math.ceil(x.length / 8);

const byteArray = new Uint8Array(byteLength);

for (let i = 0; i < byteLength; i++) {
    const byteStart = i * 8;
    const byteEnd = byteStart + 8;
    byteArray[i] = parseInt(x.slice(byteStart, byteEnd), 2);
}

console.log(byteArray)