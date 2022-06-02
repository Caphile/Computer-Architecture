enum accessType { RD, WR };
enum accessSize { BYTE, HALF, WORD };

int MEM(unsigned int A, int V, int nRW, int S);

unsigned int memoryRead(unsigned int addr);

void memoryWrite(unsigned int addr, unsigned int data);

void resetMem(void);