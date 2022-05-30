void printShift(unsigned int op, unsigned int rd, unsigned int rt, unsigned int sht);
void printJr(unsigned int op, unsigned int rs);

void printSyscall(unsigned int op);

void printMfHiLo(unsigned int op, unsigned int rd);

void printMul(unsigned int op, unsigned int rs, unsigned int rt);

void printALU(unsigned int op, unsigned int rd, unsigned int rs, unsigned int rt);

void printALUI(unsigned int op, unsigned int rt, unsigned int rs, unsigned int immediate);

void printBranch(unsigned int op, unsigned int rs, unsigned int rt, int offset);

void printJump(unsigned int op, unsigned int offset);

void printLoadStore(unsigned int op, unsigned int rt, unsigned int rs, int offset);

#pragma once
