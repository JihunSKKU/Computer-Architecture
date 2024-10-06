// https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
// 116page
// file:///C:/Users/KimJiHun/Desktop/3%ED%95%99%EB%85%84%201%ED%95%99%EA%B8%B0/%EC%BB%B4%EA%B5%AC%EA%B0%9C/CA_Proj1.pdf

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "File open error (%s)\n", argv[1]);
        return 1;
    }

    // Open binary file in read mode
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "File open error (%s)\n", argv[1]);
        return 1;
    }

    int inst_count = 0;
    unsigned int inst;
    
    while(fread(&inst, sizeof(inst), 1, fp) != 0) {
        printf("inst %d: %08x ", inst_count, inst);
        inst_count++;

        // Decode the instruction
        unsigned int opcode = inst & 0x7f;

        // R-format
        if(opcode == 0b0110011) {
            unsigned int rd = (inst >> 7) & 0x1f;
            unsigned int funct3 = (inst >> 12) & 0x7;
            unsigned int rs1 = (inst >> 15) & 0x1f;
            unsigned int rs2 = (inst >> 20) & 0x1f;
            unsigned int funct7 = (inst >> 25) & 0x7f;
            
            if(funct3 == 0b000 && funct7 == 0b0000000)
                printf("add ");
            else if(funct3 == 0b000 && funct7 == 0b0100000)
                printf("sub ");
            else if(funct3 == 0b001 && funct7 == 0b0000000)
                printf("sll ");
            else if(funct3 == 0b010 && funct7 == 0b0000000)
                printf("slt ");
            else if(funct3 == 0b011 && funct7 == 0b0000000)
                printf("sltu ");
            else if(funct3 == 0b100 && funct7 == 0b0000000)
                printf("xor ");
            else if(funct3 == 0b101 && funct7 == 0b0000000)
                printf("srl ");
            else if(funct3 == 0b101 && funct7 == 0b0100000)
                printf("sra ");
            else if(funct3 == 0b110 && funct7 == 0b0000000)
                printf("or ");
            else if(funct3 == 0b111 && funct7 == 0b0000000)
                printf("and ");
            else {
                printf("unknown instruction\n");
                continue;
            }

            printf("x%d, x%d, x%d\n", rd, rs1, rs2);
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
                if(funct3 == 0b000)
                    printf("jalr x%d, %d(x%d)\n", rd, imm, rs1);
                else {
                    printf("unknown instruction\n");
                    continue;
                }
            }

            else if(opcode == 0b0000011) {
                if(funct3 == 0b000)
                    printf("lb ");
                else if(funct3 == 0b001)
                    printf("lh ");
                else if(funct3 == 0b010)
                    printf("lw ");
                else if(funct3 == 0b100)
                    printf("lbu ");
                else if(funct3 == 0b101)
                    printf("lhu ");
                else {
                    printf("unknown instruction\n");
                    continue;
                }
                printf("x%d, %d(x%d)\n", rd, imm, rs1);
            }

            else if(opcode == 0b0010011) {
                if(funct3 != 0b001 && funct3 != 0b101) {
                    if(funct3 == 0b000)
                        printf("addi ");
                    else if(funct3 == 0b010)
                        printf("slti ");
                    else if(funct3 == 0b011)
                        printf("sltiu ");
                    else if(funct3 == 0b100)
                        printf("xori ");
                    else if(funct3 == 0b110)
                        printf("ori ");
                    else if(funct3 == 0b111)
                        printf("andi ");
                    printf("x%d, x%d, %d\n", rd, rs1, imm);
                }
                else {
                    unsigned int funct7 = (imm >> 5) & 0x7f;
                    unsigned int shamt = imm & 0x1f;
                    
                    if(funct3 == 0b001 && funct7 == 0b0000000)
                        printf("slli ");
                    else if(funct3 == 0b101 && funct7 == 0b0000000)
                        printf("srli ");
                    else if(funct3 == 0b101 && funct7 == 0b0100000)
                        printf("srai ");
                    else {
                        printf("unknown instruction\n");
                        continue;
                    }
                    printf("x%d, x%d, %d\n", rd, rs1, shamt);
                }
            }
        }

        // S-format
        else if(opcode == 0b0100011) {
            unsigned int imm = (inst >> 7) & 0x1f;
            unsigned int funct3 = (inst >> 12) & 0x7;
            unsigned int rs1 = (inst >> 15) & 0x1f;
            unsigned int rs2 = (inst >> 20) & 0x1f;
            imm |= (inst >> 20) & 0xfe0;
            if(imm >> 11)
                imm |= 0xfffff000;

            if(funct3 == 0b000)
                printf("sb ");
            else if(funct3 == 0b001)
                printf("sh ");
            else if(funct3 == 0b010)
                printf("sw ");
            else {
                printf("unknown instruction\n");
                continue;
            }

            printf("x%d, %d(x%d)\n", rs2, imm, rs1);
        }

        // SB-format
        else if(opcode == 0b1100011) {
            unsigned int imm = (inst << 4) & 0x800;
            imm |= (inst >> 7) & 0x1e;
            unsigned int funct3 = (inst >> 12) & 0x7;
            unsigned int rs1 = (inst >> 15) & 0x1f;
            unsigned int rs2 = (inst >> 20) & 0x1f;
            imm |= (inst >> 20) & 0x7e0;
            imm |= (inst >> 19) & 0x1000;
            if(imm >> 12)
                imm |= 0xffffe000;

            if(funct3 == 0b000)
                printf("beq ");
            else if(funct3 == 0b001)
                printf("bne ");
            else if(funct3 == 0b100)
                printf("blt ");
            else if(funct3 == 0b101)
                printf("bge ");
            else if(funct3 == 0b110)
                printf("bltu ");
            else if(funct3 == 0b111)
                printf("bgeu ");
            else {
                printf("unknown instruction\n");
                continue;
            }
            
            printf("x%d, x%d, %d\n", rs1, rs2, imm);
        }

        // U-format
        else if(opcode == 0b0110111 || opcode == 0b0010111) {
            unsigned int rd = (inst >> 7) & 0x1f;
            unsigned int imm = inst & 0xfffff000;

            if(opcode == 0b0110111)
                printf("lui ");
            else
                printf("auipc ");

            printf("x%d, %d\n", rd, imm);
        }

        // UJ-format
        else if(opcode == 0b1101111) {
            unsigned int rd = (inst >> 7) & 0x1f;
            unsigned int imm = (inst >> 20) & 0x7fe;
            imm |= (inst >> 9) & 0x800;
            imm |= inst & 0xff000;
            imm |= (inst >> 11) & 0x100000;
            if(imm >> 20)
                imm |= 0xffe00000;

            printf("jal x%d, %d\n", rd, imm);
        }

        // unknown instruction (opcode incorrect)
        else
            printf("unknown instruction\n");
    }
    
    fclose(fp);
    return 0;
}