// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_uradd16(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_URADD16));
  #include "insns/uradd16.h"
  trace_opcode(p,  MATCH_URADD16, insn);
  #undef xlen
  return npc;
}

reg_t rv64_uradd16(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_URADD16));
  #include "insns/uradd16.h"
  trace_opcode(p,  MATCH_URADD16, insn);
  #undef xlen
  return npc;
}
