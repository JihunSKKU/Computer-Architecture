// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vsm_v(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VSM_V));
  #include "insns/vsm_v.h"
  trace_opcode(p,  MATCH_VSM_V, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vsm_v(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VSM_V));
  #include "insns/vsm_v.h"
  trace_opcode(p,  MATCH_VSM_V, insn);
  #undef xlen
  return npc;
}
