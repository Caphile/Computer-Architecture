#include <stdio.h>

enum accessType { RD, WR };

const int R_SIZE = 32;
unsigned int R[R_SIZE];

int PC = 0x400000;
int HI = 0;
int LO = 0;

unsigned int REG(unsigned int A, unsigned int V, unsigned int nRW) {
	if (nRW == RD) return R[A];
	else if (nRW == WR) R[A] = V;
	return 0;
}

void resetREG() {
	for (int i = 0; i < R_SIZE; i++) {
		REG(i, 0, WR);
	}
	HI = 0;
	LO = 0;
	REG(29, 0x80000000, WR);
	//REG($sp, 0x80000000, WR);
}