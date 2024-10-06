// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_kmmawb2(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_KMMAWB2));
  #include "insns/kmmawb2.h"
  trace_opcode(p,  MATCH_KMMAWB2, insn);
  #undef xlen
  return npc;
}

reg_t rv64_kmmawb2(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_KMMAWB2));
  #include "insns/kmmawb2.h"
  trace_opcode(p,  MATCH_KMMAWB2, insn);
  #undef xlen
  return npc;
}
