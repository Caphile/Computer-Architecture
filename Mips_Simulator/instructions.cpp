#include <stdio.h>
#include "memory.h"
#include "register.h"
#include "defines.h"
#include "ALU.h"
#include "tools.h"

extern int PC;
extern int HI;
extern int LO;

extern unsigned int* R;

void INOP() {
	return;
}

void Isll(int rd, int rt, int sh) {
	R[rd] = ALU(R[rt], sh, SLL, NULL);
}
void Isrl(int rd, int rt, int sh) {
	R[rd] = ALU(R[rt], sh, SRL, NULL);
}
void Isra(int rd, int rt, int sh) {
	R[rd] = ALU(R[rt], sh, SRA, NULL);
}

void Islt(int rd, int rs, int rt) {
	R[rd] = ALU(R[rs], R[rt], SLT, NULL);
}

void Imfhi(int rd) {
	R[rd] = HI;
}
void Imflo(int rd) {
	R[rd] = LO;
}
void Imul(int rs, int rt) {
	long long int result = (long long int)R[rs] * (long long int)R[rt];
	HI = result >> 32;
	LO = (result << 32) >> 32;
}

void Iadd(int rd, int rs, int rt){
	R[rd] = ALU(R[rs], R[rt], ADD, NULL);
}
void Isub(int rd, int rs, int rt) {
	R[rd] = ALU(R[rs], R[rt], SUB, NULL);
}

void Ijr(int rs) {
	PC = R[rs];
}
void Isyscall() {
	if (R[2] == 1)
		printf("%d\n", R[2]);
	else if (R[2] == 11)
		printf("%c\n", R[2]);
}

void Iand(int rd, int rs, int rt) {
	R[rd] = ALU(R[rs], R[rt], AND, NULL);
}
void Ior(int rd, int rs, int rt) {
	R[rd] = ALU(R[rs], R[rt], OR, NULL);
}
void Ixor(int rd, int rs, int rt) {
	R[rd] = ALU(R[rs], R[rt], XOR, NULL);
}
void Inor(int rd, int rs, int rt) {
	R[rd] = ALU(R[rs], R[rt], NOR, NULL);
}

void Ilb(int rt, int imm, int rs) {
	R[rt] = MEM(R[rs] + imm, 0, RD, BYTE);
}
void Isb(int rt, int imm, int rs) {
	MEM(R[rs] + imm, R[rt], WR, BYTE);
}
void Ilw(int rt, int imm, int rs) {
	R[rt] = MEM(R[rs] + imm, 0, RD, WORD);
}
void Isw(int rt, int imm, int rs) {
	MEM(imm + R[rs], R[rt], WR, WORD);
}

void Islti(int rt, int rs, int imm) {
	R[rt] = ALU(R[rs], imm, SLTI, NULL);
}
void Ibltz(int rs, int rt, int imm) {
	if (R[rs] < R[rt]) PC += imm * 4;
}

void Ij(int address) {
	PC = ((PC + 4) & 0xf0000000) | (address << 2);
}
void Ijal(int address) {
	R[31] = PC;
	PC = ((PC + 4) & 0xf0000000) | (address << 2);
}

void Iaddi(int rt, int rs, int imm) {
	R[rt] = ALU(R[rs], imm, ADDI, NULL);
}

void Ilbu(int rt, int imm, int rs) {
	R[rt] = MEM(R[rs] + imm, 0, RD, BYTE);
}

void Ibeq(int rs, int rt, int imm) {
	if (R[rs] == R[rt]) PC += imm * 4;
}
void Ibne(int rs, int rt, int imm) {
	if (R[rs] != R[rt]) PC += imm * 4;
}

void Iandi(int rt, int rs, int imm) {
	R[rt] = ALU(R[rs], imm, ANDI, NULL);
}
void Iori(int rt, int rs, int imm) {
	R[rt] = ALU(R[rs], imm, ORI, NULL);
}
void Ixori(int rt, int rs, int imm) {
	R[rt] = ALU(R[rs], imm, XORI, NULL);
}
void Ilui(int rt, int imm) {
	R[rt] = (imm & 0xffff) << 16;
}