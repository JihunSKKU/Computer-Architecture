// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_ukcrsa32(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_UKCRSA32));
  #include "insns/ukcrsa32.h"
  trace_opcode(p,  MATCH_UKCRSA32, insn);
  #undef xlen
  return npc;
}

reg_t rv64_ukcrsa32(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_UKCRSA32));
  #include "insns/ukcrsa32.h"
  trace_opcode(p,  MATCH_UKCRSA32, insn);
  #undef xlen
  return npc;
}
