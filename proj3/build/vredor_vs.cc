// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vredor_vs(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VREDOR_VS));
  #include "insns/vredor_vs.h"
  trace_opcode(p,  MATCH_VREDOR_VS, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vredor_vs(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VREDOR_VS));
  #include "insns/vredor_vs.h"
  trace_opcode(p,  MATCH_VREDOR_VS, insn);
  #undef xlen
  return npc;
}
