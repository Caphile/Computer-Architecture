void Inop();

void Isll(int rd, int rt, int sh);
void Isrl(int rd, int rt, int sh);
void Isra(int rd, int rt, int sh);

void Islt(int rd, int rs, int rt);

void Imfhi(int rd);
void Imflo(int rd);
void Imul(int rs, int rt);

void Iadd(int rd, int rs, int rt);
void Isub(int rd, int rs, int rt);

void Ijr(int rs);
void Isyscall();

void Iand (int rd, int rs, int rt);
void Ior(int rd, int rs, int rt);
void Ixor(int rd, int rs, int rt);
void Inor(int rd, int rs, int rt);

void Ilb(int rt, int imm, int rs);
void Isb(int rt, int imm, int rs);
void Ilw(int rt, int imm, int rs);
void Isw(int rt, int imm, int rs);

void Islti(int rt, int rs, int imm);
void Ibltz(int rs, int rt, int imm);

void Ij(int address);
void Ijal(int address);

void Iaddi(int rt, int rs, int imm);

void Ilbu(int rt, int imm, int rs);

void Ibeq(int rs, int rt, int imm);
void Ibne(int rs, int rt, int imm);

void Iandi(int rt, int rs, int imm);
void Iori(int rt, int rs, int imm);
void Ixori(int rt, int rs, int imm);
void Ilui(int rt, int imm);
