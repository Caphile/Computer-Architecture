#include <stdio.h>

unsigned int invertEndian(unsigned int data)
{
	unsigned char c[4];

	c[3] = (unsigned char)data; data >>= 8;
	c[2] = (unsigned char)data; data >>= 8;
	c[1] = (unsigned char)data; data >>= 8;
	c[0] = (unsigned char)data;

	return *(unsigned int*)c;
}