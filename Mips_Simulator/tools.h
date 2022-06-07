unsigned int invertEndian(unsigned int data);

union instructionRegister fetchInstruction();

enum accessType { RD, WR };
enum accessSize { BYTE, HALF, WORD };