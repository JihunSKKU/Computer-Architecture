// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vnsrl_wi(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VNSRL_WI));
  #include "insns/vnsrl_wi.h"
  trace_opcode(p,  MATCH_VNSRL_WI, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vnsrl_wi(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VNSRL_WI));
  #include "insns/vnsrl_wi.h"
  trace_opcode(p,  MATCH_VNSRL_WI, insn);
  #undef xlen
  return npc;
}
