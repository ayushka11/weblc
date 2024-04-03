#include <stdio.h>
#include <stdint.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>
#include <sys/mman.h>
#include <emscripten.h>
#include <strings.h>

#define MEMORY_MAX (1 << 16)
uint16_t memory[MEMORY_MAX];


enum
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, //program counter
    R_COND, //condition flag
    R_COUNT
};

uint16_t reg[R_COUNT];

enum
{
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2, /* N */
};

enum
{
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};

int alerter(){
    emscripten_run_script("alert('The VM has started')");
}

uint16_t sign_extend(uint16_t x, int bit_count)
{
    if ((x >> (bit_count - 1)) & 1) {
        x |= (0xFFFF << bit_count);
    }
    return x;
}

void update_flags(uint16_t r)
{
    if (reg[r] == 0)
    {
        reg[R_COND] = FL_ZRO;
    }
    else if (reg[r] >> 15)
    {
        reg[R_COND] = FL_NEG;
    }
    else
    {
        reg[R_COND] = FL_POS;
    }
}


// inline const char* cstr(const std::string& message) {           //this function converts a string into a form that can be returned.
//     char * cstr = new char [message.length()+1];
//     strcpy (cstr, message.c_str());
//     return cstr;
// }

// EMSCRIPTEN_KEEPALIVE const char* CountRegisterJSFunction() {
// 	char reg_string[256];
//     int reg_string_index = 0;

//     for (int i = 0; i < R_COUNT; i++) {
//         reg_string_index += sprintf(reg_string + reg_string_index, "%d ", reg[i]);
//     }
//     return cstr(reg_string);
// };


int main(int argc, const char* argv[])
{
    printf("This line printing tests entry into the main function");
    alerter();
    if (!read_image(argv[j]))
    {
            char* dynamic_string = malloc(sizeof(char) * MAX_LENGTH);
            if (dynamic_string == NULL) {
                printf("Failed to allocate memory for dynamic string\n");
                exit(1);
            }
            free(dynamic_string);
            printf("failed to load assembly: %s\n", );
            emscripten_run_script("alert('File could not load')");
            exit(1);
    }
    //@{Setup}

    reg[R_COND] = FL_ZRO;
    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;

    int running = 1;
    while (running)
    {
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

        switch (op)
        {
            case OP_ADD:
            {
                uint16_t r0 = (instr >> 9) & 0x7;
                uint16_t r1 = (instr >> 6) & 0x7;
                uint16_t imm_flag = (instr >> 5) & 0x1;

                if (imm_flag)
                {
                    uint16_t imm5 = sign_extend(instr & 0x1F, 5);
                    reg[r0] = reg[r1] + imm5;
                }
                else
                {
                    uint16_t r2 = instr & 0x7;
                    reg[r0] = reg[r1] + reg[r2];
                }

                update_flags(r0);
            }
                break;
            case OP_AND:
                //@{AND}
                break;
            case OP_NOT:
                //@{NOT}
                break;
            case OP_BR:
                //@{BR}
                break;
            case OP_JMP:
                //@{JMP}
                break;
            case OP_JSR:
                //@{JSR}
                break;
            case OP_LD:
                //@{LD}
                break;
            case OP_LDI:
                //@{LDI}
                break;
            case OP_LDR:
                //@{LDR}
                break;
            case OP_LEA:
                //@{LEA}
                break;
            case OP_ST:
                //@{ST}
                break;
            case OP_STI:
                //@{STI}
                break;
            case OP_STR:
                //@{STR}
                break;
            case OP_TRAP:
                //@{TRAP}
                break;
            case OP_RES:
            case OP_RTI:
            default:
                //@{BAD OPCODE}
                break;
        }
    }
    //@{Shutdown}
}