// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vmsof_m(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VMSOF_M));
  #include "insns/vmsof_m.h"
  trace_opcode(p,  MATCH_VMSOF_M, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vmsof_m(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VMSOF_M));
  #include "insns/vmsof_m.h"
  trace_opcode(p,  MATCH_VMSOF_M, insn);
  #undef xlen
  return npc;
}
