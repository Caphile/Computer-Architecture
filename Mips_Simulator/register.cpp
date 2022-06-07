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
	REG(29, 0x80000000, WR);	// $sp
}

void viewRegister() {
	printf("\033[0;32m"); 
	printf("------------------------\n");
	printf("| register |   value   |\n");
	printf("|----------------------|\n");
	printf("| %8s | %9x |\n", "PC", PC);
	printf("| %8s | %9x |\n", "HI", HI);
	printf("| %8s | %9x |\n", "LO", LO);
	printf("|          |           |\n");
	for (int i = 0; i < R_SIZE; i++) {
		// 각각의 레지스터 읽어오기
		char* name = REGISTER_STR[i];
		unsigned int value = REG(i, 0, RD);
		printf("| %8s | %9x |\n", name, value);
	}
	printf("------------------------\n");
	printf("\033[0m");
}