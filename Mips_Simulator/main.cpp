#include <stdio.h>
#include "tools.h"
#include "memory.h"
#include "register.h"
#include "decode.h"
#include "defines.h"

void main() {



    int counter = 0;
    extern int IR;
    char cmd;
    bool isEnd = false;
    while (not isEnd) {
        

        scanf_s("%c", &cmd);
        
        if (cmd == 'l') {
                FILE* pFile = nullptr;

                //const char* fileName = "as_ex01_arith.bin";
                //const char* fileName = "as_ex02_logic.bin";
                //const char* fileName = "as_ex03_ifelse.bin";
                const char* fileName = "as_ex04_fct.bin";

                unsigned int data;
                unsigned int addr;
                unsigned int iCount;	// # of instructions
                unsigned int dCount;	// # of data

                fopen_s(&pFile, fileName, "rb");

                // read instruction and data numbers
                fread(&data, sizeof(data), 1, pFile);
                iCount = invertEndian(data);
                fread(&data, sizeof(data), 1, pFile);
                dCount = invertEndian(data);
                printf("Number of Instructions: %d, Number of Data: %d\n", iCount, dCount);

                extern int PC;
                resetMem();
                resetREG();

                addr = 0;
                for (int i = 0; i < (int)iCount; i++) {
                    fread(&data, sizeof(unsigned int), 1, pFile);
                    data = invertEndian(data);
                    memoryWrite(addr, data);
                    addr += 4;
                }
                fclose(pFile);

        }
        else if (cmd == 'j') {
                printf("target address : ");
                scanf("%d", &target_address); 
                PC = target_address;
            

        }
        else if (cmd == 'g') {
            for (; counter <= iCount; counter++) {
                IR = memoryRead(PC); // instruction fetch
                PC += 4;
                execute(); // instruction decode
            }
        }
        else if (cmd == 's') {
            counter += 1;
            IR = memoryRead(PC); // instruction fetch
            PC += 4;
            execute(); // instruction decode
        }
        else if (cmd == 'm') {
            unsigned int m_start=0, m_end = 0;
            printf("<start><end>\n");
            scanf("%u%u",&m_start,&m_end);
            // ม๘วเม฿
        }
        else if (cmd == 'r') {
            viewRegister();
        }
        else if (cmd == 'x') {
            isEnd = true;
        }
        else if (cmd == 'sr') {

        }
        else if (cmd == 'sm') {
            unsigned int m_addr = 0; //address
            unsigned int m_value = 0; //memory_value
            printf("<addr><value>\n");
            scanf("%u%u", &m_addr, &m_value);
            memoryWrite(m_addr, m_value);
        }
    }
}
