// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_fsgnj_s(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FSGNJ_S));
  #include "insns/fsgnj_s.h"
  trace_opcode(p,  MATCH_FSGNJ_S, insn);
  #undef xlen
  return npc;
}

reg_t rv64_fsgnj_s(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FSGNJ_S));
  #include "insns/fsgnj_s.h"
  trace_opcode(p,  MATCH_FSGNJ_S, insn);
  #undef xlen
  return npc;
}
