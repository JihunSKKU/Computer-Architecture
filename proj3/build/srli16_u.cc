// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_srli16_u(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_SRLI16_U));
  #include "insns/srli16_u.h"
  trace_opcode(p,  MATCH_SRLI16_U, insn);
  #undef xlen
  return npc;
}

reg_t rv64_srli16_u(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_SRLI16_U));
  #include "insns/srli16_u.h"
  trace_opcode(p,  MATCH_SRLI16_U, insn);
  #undef xlen
  return npc;
}
