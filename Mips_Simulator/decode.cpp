#include <stdio.h>
#include "memory.h"
#include "register.h"
#include "instructions.h"
#include "tools.h"
#include "defines.h"

unsigned int IR;	// Instruction Register'
extern int PC;

unsigned int fct;
unsigned int sht;
unsigned int rd;
unsigned int rt;
unsigned int rs;
unsigned int opc;
unsigned int addr;
unsigned int imm;

// R-type instructin decoding
void decodeRtype(unsigned int fct) {
	unsigned int fcth, fctl;

	fctl = fct & 0x7;
	fcth = (fct & 0x38) >> 3;

	if (fcth == 0) {
		if (fctl == 0) {
			printf("sll\n");
			Isll(rd, rt, sht);
		}
		else if (fctl == 2) {
			printf("srl\n");
			Isrl(rd, rt, sht);
	}
		else if (fctl == 4) {
			printf("sra\n");
			Isra(rd, rt, sht);
		}
		else printf("Undefined instruction\n");
	}
	else if (fcth == 1) {
		if (fctl == 0) {
			printf("jr\n");
			Ijr(rs);
		}
		else if (fctl == 4) {
			printf("syscall\n");
			Isyscall();
		}
		else printf("Undefined instruction\n");
	}
	else if (fcth == 2) {
		if (fctl == 0) {
			printf("mfhi\n");
			Imfhi(rd);
		}
		else if (fctl == 2) {
			printf("mflo\n");
			Imflo(rd);
		}
		else printf("Undefined instruction\n");
	}
	else if (fcth == 3) {
		if (fctl == 0) {
			printf("mul\n");
			Imul(rs, rt);
		}
		else printf("Undefined instruction\n");
	}
	else if (fcth == 4) {
		if (fctl == 0) {
			printf("add\n");
			Iadd(rd, rs, rt);
		}
		else if (fctl == 2) { 
			printf("sub\n"); 
			Isub(rd, rs, rt);
		}
		else if (fctl == 4) {
			printf("and\n");
			Iand(rd, rs, rt);
		}
		else if (fctl == 5) {
			printf("or\n");
			Ior(rd, rs, rt);
		}
		else if (fctl == 6) {
			printf("xor\n");
			Ixor(rd, rs, rt);
		}
		else if (fctl == 7) {
			printf("nor\n");
			Inor(rd, rs, rt);
		}
		else printf("Undefined instruction\n");
	}
	else if (fcth == 5) {
		if (fctl == 2) {
			printf("slt\n");
			Islt(rd, rs, rt);
		}
		else printf("Undefined instruction\n");
	}
	else printf("Undefined instruction\n");
}

// instruction decoding
void instructionDecode(void) {
	unsigned int opc, fct;
	unsigned int opch, opcl;

	opc = IR >> 26;
	fct = IR & 0x3f;

	printf("Opc: %2x, Fct: %2x, Inst: ", opc, fct);

	opcl = opc & 0x7;
	opch = (opc & 0x38) >> 3;

	if (opch == 0) {
		if (opcl == 0) {
			decodeRtype(fct);
		}
		else if (opcl == 1) {
			printf("bltz\n");
			Ibltz(rs, rt, imm);
		}
		else if (opcl == 2) {
			printf("j\n");
			Ij(addr);
		}
		else if (opcl == 3) {
			printf("jal\n");
			Ijal(addr);
		}
		else if (opcl == 4) {
			printf("beq\n");
			Ibeq(rs, rt, imm);
		}
		else if (opcl == 5) {
			printf("bne\n");
			Ibne(rs, rt, imm);
		}
		else printf("Undefined instruction\n");
	}
	else if (opch == 1) {
		if (opcl == 0) {
			printf("addi\n");
			Iaddi(rt, rs, imm);
		}
		else if (opcl == 2) {
			printf("slti\n");
			Islti(rt, rs, imm);
		}
		else if (opcl == 4) {
			printf("andi\n");
			Iandi(rt, rs, imm & 0xffff);
		}
		else if (opcl == 5) {
			printf("ori\n");
			Iori(rt, rs, imm & 0xffff);
		}
		else if (opcl == 6) {
			printf("xori\n");
			Ixori(rt, rs, imm & 0xffff);
		}
		else if (opcl == 7) {
			printf("lui\n");
			Ilui(rt, imm & 0xffff);
		}
		else printf("Undefined instruction\n");
	}
	else if (opch == 4) {
		if (opcl == 0) {
			printf("lb\n");
			Ilb(rt, imm, rs);
		}
		else if (opcl == 3) {
			printf("lw\n");
			Ilw(rt, imm, rs);
		}
		else if (opcl == 4) {
			printf("lbu\n");
			Ilbu(rt, imm, rs);
		}
		else printf("Undefined instruction\n");
	}
	else if (opch == 5) {
		if (opcl == 0) {
			printf("sb\n");
			Isb(rt, imm, rs);
		}
		else if (opcl == 3) {
			printf("sw\n");
			Isw(rt, imm, rs);
		}
		else printf("Undefined instruction\n");
	}
	else printf("Undefined instruction\n");
}

void execute() {
	union instructionRegister instruction = fetchInstruction();

	fct = instruction.RI.fct;
	sht = instruction.RI.sht;
	rd = instruction.RI.rd;
	rt = instruction.RI.rt;
	rs = instruction.RI.rs;
	opc = instruction.RI.opc;
	addr = instruction.JI.jval;
	imm = instruction.II.offset & 0xffff;

	instructionDecode();
}