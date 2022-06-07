#include <stdio.h>
#include "register.h"
#include "memory.h"
#include "defines.h"
#include "tools.h"

extern int PC;

unsigned int invertEndian(unsigned int data)
{
	unsigned char c[4];

	c[3] = (unsigned char)data; data >>= 8;
	c[2] = (unsigned char)data; data >>= 8;
	c[1] = (unsigned char)data; data >>= 8;
	c[0] = (unsigned char)data;

	return *(unsigned int*)c;
}

union instructionRegister fetchInstruction() {
	unsigned int word = MEM(PC, 0, RD, WORD);
	union instructionRegister instruction = { word };
	PC += 4;

	return instruction;
}