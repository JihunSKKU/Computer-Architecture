// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_sh2add_uw(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_SH2ADD_UW));
  #include "insns/sh2add_uw.h"
  trace_opcode(p,  MATCH_SH2ADD_UW, insn);
  #undef xlen
  return npc;
}

reg_t rv64_sh2add_uw(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_SH2ADD_UW));
  #include "insns/sh2add_uw.h"
  trace_opcode(p,  MATCH_SH2ADD_UW, insn);
  #undef xlen
  return npc;
}
