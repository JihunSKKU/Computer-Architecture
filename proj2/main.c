#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 0x10000 // data memory size : 64KB
#define MEM_START 0x10000000
#define DECIMAL 0x20000000
#define REG_SIZE 32

unsigned int insts[MEM_SIZE/4];
unsigned int mem[MEM_SIZE/4];
int reg[REG_SIZE];

void print_registers();
int execute_inst(int pc);

int main(int argc, char *argv[]) {
    if(argc != 3 && argc != 4) {
        fprintf(stderr, "Usage:\n%s instruction_file_name [data_file_name] #_of_instrs_to_execute\n", argv[0]);
        return 1;
    }

    // Load binary instruction file
    FILE *fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        fprintf(stderr, "File open error (%s)\n", argv[1]);
        return 1;
    }

    unsigned int inst_idx = 0;
    unsigned int token;
    while(fread(&token, sizeof(token), 1, fp) != 0) {
        insts[inst_idx++] = token;
    }
    fclose(fp);

    // Load binary data file
    for(int i = 0; i < MEM_SIZE/4; i++)
        mem[i] = 0xFF;

    if(argc == 4) {
        fp = fopen(argv[2], "rb");
        if(fp == NULL) {
            fprintf(stderr, "File open error (%s)\n", argv[2]);
            return 1;
        }

        unsigned int mem_idx = 0;
        while(fread(&token, sizeof(token), 1, fp) != 0) {
            mem[mem_idx++] = token;
        }
        fclose(fp);
    }

    // Execute instructions
    int pc = 0x00000000;
    int num_inst = atoi(argv[argc - 1]);
    fp = fopen(argv[1], "rb");

    for(int i = 0; i < num_inst; i++) {
        pc = execute_inst(pc);
        if(pc < 0x00000000 || pc >= 0x10000000) {
            fprintf(stderr, "PC out of range\n");
            return 2;
        }
    }
    print_registers();
    
    return 0;
}

void print_registers() { 
    for(int i = 0; i < REG_SIZE; i++)
        printf("x%d: 0x%08x\n", i, reg[i]);
}

int execute_inst(int pc) {
    unsigned int inst = insts[pc/4];
    // printf("inst %d: %08x ", inst_count, inst);
    // inst_count++;

    // Decode the instruction
    unsigned int opcode = inst & 0x7f;

    // R-format
    if(opcode == 0b0110011) {
        unsigned int rd = (inst >> 7) & 0x1f;
        unsigned int funct3 = (inst >> 12) & 0x7;
        unsigned int rs1 = (inst >> 15) & 0x1f;
        unsigned int rs2 = (inst >> 20) & 0x1f;
        unsigned int funct7 = (inst >> 25) & 0x7f;
        
        if(funct3 == 0b000 && funct7 == 0b0000000) {
            // printf("add ");
            reg[rd] = reg[rs1] + reg[rs2];
            pc += 4;
        }

        else if(funct3 == 0b000 && funct7 == 0b0100000) {
            // printf("sub ");
            reg[rd] = reg[rs1] - reg[rs2];
            pc += 4;
        }

        else if(funct3 == 0b001 && funct7 == 0b0000000) {
            // printf("sll ");
            reg[rd] = reg[rs1] << ((unsigned)reg[rs2] % 32);
            pc += 4;
        }

        else if(funct3 == 0b010 && funct7 == 0b0000000) {
            // printf("slt ");
            if(reg[rs1] < reg[rs2])
                reg[rd] = 1;
            else
                reg[rd] = 0;
            pc += 4;
        }

        else if(funct3 == 0b011 && funct7 == 0b0000000) {
            // printf("sltu ");
            if((unsigned)reg[rs1] < reg[rs2])
                reg[rd] = 1;
            else
                reg[rd] = 0;
            pc += 4;
        }

        else if(funct3 == 0b100 && funct7 == 0b0000000) {
            // printf("xor ");
            reg[rd] = reg[rs1] ^ reg[rs2];
            pc += 4;
        }

        else if(funct3 == 0b101 && funct7 == 0b0000000) {
            // printf("srl ");
            reg[rd] = (unsigned)reg[rs1] >> ((unsigned)reg[rs2] % 32);
            pc += 4;
        }

        else if(funct3 == 0b101 && funct7 == 0b0100000) {
            // printf("sra ");
            reg[rd] = reg[rs1] >> ((unsigned)reg[rs2] % 32);
            pc += 4;
        }

        else if(funct3 == 0b110 && funct7 == 0b0000000) {
            // printf("or ");
            reg[rd] = reg[rs1] | reg[rs2];
            pc += 4;
        }

        else if(funct3 == 0b111 && funct7 == 0b0000000) {
            // printf("and ");
            reg[rd] = reg[rs1] & reg[rs2];
            pc += 4;
        }

        else {
            // printf("unknown instruction\n");
            // continue;
        }
        // printf("x%d, x%d, x%d\n", rd, rs1, rs2);
    }

    // I-format
    else if(opcode == 0b1100111 || opcode == 0b0000011 || opcode == 0b0010011) {
        unsigned int rd = (inst >> 7) & 0x1f;
        unsigned int funct3 = (inst >> 12) & 0x7;
        unsigned int rs1 = (inst >> 15) & 0x1f;
        int imm = (inst >> 20) & 0xfff;
        if(imm >> 11)
            imm |= 0xfffff000;

        if(opcode == 0b1100111) {
            if(funct3 == 0b000) {
                // printf("jalr x%d, %d(x%d)\n", rd, imm, rs1);
                reg[rd] = pc + 4;
                pc = imm + reg[rs1];
            }
            else {
                // printf("unknown instruction\n");
                // continue;
            }
        }

        else if(opcode == 0b0000011) {
            if(funct3 == 0b000);
                // printf("lb ");
            else if(funct3 == 0b001);
                // printf("lh ");
            else if(funct3 == 0b010) {
                // printf("lw ");
                unsigned int addr = imm + reg[rs1];
                if(addr <= MEM_SIZE + MEM_START && addr >= MEM_START)
                    reg[rd] = mem[(addr - MEM_START)/4];
                else if(addr == DECIMAL) {
                    int user_input;
                    scanf("%d", &user_input);
                    reg[rd] = user_input;
                }
                pc += 4;
            }
            else if(funct3 == 0b100);
                // printf("lbu ");
            else if(funct3 == 0b101);
                // printf("lhu ");
            else {
                // printf("unknown instruction\n");
                // continue;
            }
            // printf("x%d, %d(x%d)\n", rd, imm, rs1);
        }

        else if(opcode == 0b0010011) {
            if(funct3 != 0b001 && funct3 != 0b101) {
                if(funct3 == 0b000) {
                    // printf("addi ");
                    reg[rd] = reg[rs1] + imm;
                    pc += 4;
                }

                else if(funct3 == 0b010) {
                    // printf("slti ");
                    if(reg[rs1] < imm)
                        reg[rd] = 1;
                    else
                        reg[rd] = 0;
                    pc += 4;
                }

                else if(funct3 == 0b011) {
                    // printf("sltiu ");
                    if((unsigned)reg[rs1] < imm)
                        reg[rd] = 1;
                    else
                        reg[rd] = 0;
                    pc += 4;
                }

                else if(funct3 == 0b100) {
                    // printf("xori ");
                    reg[rd] = reg[rs1] ^ imm;
                    pc += 4;
                }

                else if(funct3 == 0b110) {
                    // printf("ori ");
                    reg[rd] = reg[rs1] | imm;
                    pc += 4;
                }

                else if(funct3 == 0b111) {
                    // printf("andi ");
                    reg[rd] = reg[rs1] & imm;
                    pc += 4;
                }

                // printf("x%d, x%d, %d\n", rd, rs1, imm);
            }

            else {
                unsigned int funct7 = (imm >> 5) & 0x7f;
                unsigned int shamt = imm & 0x1f;
                
                if(funct3 == 0b001 && funct7 == 0b0000000) {
                    // printf("slli ");
                    reg[rd] = reg[rs1] << shamt;
                    pc += 4;
                }

                else if(funct3 == 0b101 && funct7 == 0b0000000) {
                    // printf("srli ");
                    reg[rd] = (unsigned)reg[rs1] >> shamt;
                    pc += 4;
                }

                else if(funct3 == 0b101 && funct7 == 0b0100000) {
                    // printf("srai ");
                    reg[rd] = reg[rs1] >> shamt;
                    pc += 4;
                }

                else {
                    // printf("unknown instruction\n");
                    // continue;
                }
                // printf("x%d, x%d, %d\n", rd, rs1, shamt);
            }
        }
    }

    // S-format
    else if(opcode == 0b0100011) {
        int imm = (inst >> 7) & 0x1f;
        unsigned int funct3 = (inst >> 12) & 0x7;
        unsigned int rs1 = (inst >> 15) & 0x1f;
        unsigned int rs2 = (inst >> 20) & 0x1f;
        imm |= (inst >> 20) & 0xfe0;
        if(imm >> 11)
            imm |= 0xfffff000;

        if(funct3 == 0b000);
            // printf("sb ");
        else if(funct3 == 0b001);
            // printf("sh ");
        else if(funct3 == 0b010) {
            // printf("sw ");
            unsigned int addr = imm + reg[rs1];
            if(addr <= MEM_SIZE + MEM_START && addr >= MEM_START)
                mem[(addr - MEM_START)/4] = reg[rs2];
            else if(addr == DECIMAL) {
                printf("%c", reg[rs2]);
            }
            pc += 4;
        }

        else {
            // printf("unknown instruction\n");
            // continue;
        }

        // printf("x%d, %d(x%d)\n", rs2, imm, rs1);
    }

    // SB-format
    else if(opcode == 0b1100011) {
        int imm = (inst << 4) & 0x800;
        imm |= (inst >> 7) & 0x1e;
        unsigned int funct3 = (inst >> 12) & 0x7;
        unsigned int rs1 = (inst >> 15) & 0x1f;
        unsigned int rs2 = (inst >> 20) & 0x1f;
        imm |= (inst >> 20) & 0x7e0;
        imm |= (inst >> 19) & 0x1000;
        if(imm >> 12)
            imm |= 0xffffe000;

        if(funct3 == 0b000) {
            // printf("beq ");
            if(reg[rs1] == reg[rs2])
                pc += imm;
            else
                pc += 4;
        }

        else if(funct3 == 0b001) {
            // printf("bne ");
            if(reg[rs1] != reg[rs2])
                pc += imm;
            else
                pc += 4;
        }

        else if(funct3 == 0b100) {
            // printf("blt ");
            if(reg[rs1] < reg[rs2])
                pc += imm;
            else
                pc += 4;
        }
        
        else if(funct3 == 0b101) {
            // printf("bge ");
            if(reg[rs1] >= reg[rs2])
                pc += imm;
            else
                pc += 4;
        }
        else if(funct3 == 0b110) {
            // printf("bltu ");
            if((unsigned)reg[rs1] < reg[rs2])
                pc += imm;
            else
                pc += 4;
        }
        else if(funct3 == 0b111) {
            // printf("bgeu ");
            if((unsigned)reg[rs1] >= reg[rs2])
                pc += imm;
            else
                pc += 4;
        }
        else {
            // printf("unknown instruction\n");
            // continue;
        }
        
        // printf("x%d, x%d, %d\n", rs1, rs2, imm);
    }

    // U-format
    else if(opcode == 0b0110111 || opcode == 0b0010111) {
        unsigned int rd = (inst >> 7) & 0x1f;
        int imm = inst & 0xfffff000;

        if(opcode == 0b0110111) {
            // printf("lui ");
            reg[rd] = imm;
            pc += 4;
        }

        else {
            // printf("auipc ");
            reg[rd] = imm + pc;
            pc += 4;
        }

        // printf("x%d, %d\n", rd, imm);
    }

    // UJ-format
    else if(opcode == 0b1101111) {
        unsigned int rd = (inst >> 7) & 0x1f;
        int imm = (inst >> 20) & 0x7fe;
        imm |= (inst >> 9) & 0x800;
        imm |= inst & 0xff000;
        imm |= (inst >> 11) & 0x100000;
        if(imm >> 20)
            imm |= 0xffe00000;

        // printf("jal x%d, %d\n", rd, imm);
        reg[rd] = pc + 4;
        pc += imm;
    }

    // unknown instruction (opcode incorrect)
    else;
        // printf("unknown instruction\n");

    reg[0] = 0;
    return pc;
}