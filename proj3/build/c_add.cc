// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_c_add(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_C_ADD));
  #include "insns/c_add.h"
  trace_opcode(p,  MATCH_C_ADD, insn);
  #undef xlen
  return npc;
}

reg_t rv64_c_add(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_C_ADD));
  #include "insns/c_add.h"
  trace_opcode(p,  MATCH_C_ADD, insn);
  #undef xlen
  return npc;
}
