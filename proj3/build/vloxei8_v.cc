// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vloxei8_v(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VLOXEI8_V));
  #include "insns/vloxei8_v.h"
  trace_opcode(p,  MATCH_VLOXEI8_V, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vloxei8_v(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VLOXEI8_V));
  #include "insns/vloxei8_v.h"
  trace_opcode(p,  MATCH_VLOXEI8_V, insn);
  #undef xlen
  return npc;
}
