// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_hinval_vvma(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_HINVAL_VVMA));
  #include "insns/hinval_vvma.h"
  trace_opcode(p,  MATCH_HINVAL_VVMA, insn);
  #undef xlen
  return npc;
}

reg_t rv64_hinval_vvma(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_HINVAL_VVMA));
  #include "insns/hinval_vvma.h"
  trace_opcode(p,  MATCH_HINVAL_VVMA, insn);
  #undef xlen
  return npc;
}
