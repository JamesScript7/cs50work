1. What's stdint.h?

When you need to work with bit-exact signed or unsigned integer widths.
Specifically 8, 16, 32, 64 bits.

2. What's the point in using: uint8_t, uint32_t, int32_t, uint16_t?

When you have a specific bit-size you want to work with.

int can be any size >= 16 bits

The 'u' prefix in 'uint8_t' mean unsigned and holds the value from 0 through
255.
'int8_t' is signed and can hold values from -128 through 127.

1 byte || 8 bits:
'typedef uint8_t' (unsigned char)
Value: 0-255 || 0x00-0xFF

2 bytes || 16 bits:
'typedef uint16_t' (unsigned short)
Value: 0-65,535 || 0x0000-0xFFFF

4 bytes || 32 bits:
'typedef uint32_t' (unsigned int)
Value 0-4,292,967,296 || 0x00000000-0xFFFFFFFF

8 bytes || 64 bits:
'typedef uint64_t' (unsigned long long)
Value: 0-18,446,744,073,709,551,615 || 0x0000000000000000-0xFFFFFFFFFFFFFFFF

3. How many bytes are each:
'BYTE': 1 byte
'DWORD': 4 bytes
'LONG': 4 bytes
'WORD': 2 bytes

4. The two bytes that signify a BMP file:
Value is stored in 'bftype'

hexadecimal:
0x42 followed by 0x4D

ASCII:
'B' followed by 'M'

decimal:
66 followed by 77

5. What's the difference between 'bfSize' and 'biSize'?

bfSize:
File size in bytes of the full BMP (header and image)

biSize:
Files size in bytes of the header part of a BMP (BITMAPINFOHEADER)
Is constant and will always equal 40 bytes.

6. What does it mean if 'biHeight' is negative?

Then bitmap is top-down DIB with origin at the upper left corner.

7. What field in 'BITMAPINFOHEADER' specifies the BMP's color depth (bpp)?

biBitCount: bits per pixel which would give you the maximum number of colors
in the image.

8. Why might 'fopen' return 'NULL' in lines 24 and 32 'copy.c'?

line 24: If there was something wrong on opening the input file.

line 32: If there was something wrong on creating the output file.

9. Why is the third argument to 'fread' always '1' in our code?

Third argument (size_t nmemb) takes in number of elements with the
size of bytes. 1 would mean that it reads one 'char' from the file.

10. What value does line 63 of 'copy.c' assign to 'padding' if 'bi.biWidth'
is '3'?

If bi.biWidth is 3 bytes then it will add padding to make it equal to
a multiple of 4.

11. What does 'fseek' do?

12. What is 'SEEK_CUR'?
