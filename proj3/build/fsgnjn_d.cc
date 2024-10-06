// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_fsgnjn_d(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FSGNJN_D));
  #include "insns/fsgnjn_d.h"
  trace_opcode(p,  MATCH_FSGNJN_D, insn);
  #undef xlen
  return npc;
}

reg_t rv64_fsgnjn_d(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FSGNJN_D));
  #include "insns/fsgnjn_d.h"
  trace_opcode(p,  MATCH_FSGNJN_D, insn);
  #undef xlen
  return npc;
}
