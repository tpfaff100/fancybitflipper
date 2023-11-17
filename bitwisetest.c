#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int main() {
	unsigned int  n;
	for (n = 0; n <= 0xff; n++) {
printf("> "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(n));
	   n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xaaaaaaaa);
	   n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xcccccccc);
	   n = ((n >> 4) & 0x0f0f0f0f) | ((n << 4) & 0xf0f0f0f0);
	   n = ((n >> 8) & 0x00ff00ff) | ((n << 8) & 0xff00ff00);
	   n = ((n >> 16) & 0x0000ffff) | ((n << 16) & 0xffff0000);
printf(":  "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(n>>24));
	   n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xaaaaaaaa);
	   n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xcccccccc);
	   n = ((n >> 4) & 0x0f0f0f0f) | ((n << 4) & 0xf0f0f0f0);
	   n = ((n >> 8) & 0x00ff00ff) | ((n << 8) & 0xff00ff00);
	   n = ((n >> 16) & 0x0000ffff) | ((n << 16) & 0xffff0000);
printf("\n");
	}

}
