// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vl8re64_v(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VL8RE64_V));
  #include "insns/vl8re64_v.h"
  trace_opcode(p,  MATCH_VL8RE64_V, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vl8re64_v(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VL8RE64_V));
  #include "insns/vl8re64_v.h"
  trace_opcode(p,  MATCH_VL8RE64_V, insn);
  #undef xlen
  return npc;
}
