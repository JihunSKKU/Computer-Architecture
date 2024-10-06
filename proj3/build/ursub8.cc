// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_ursub8(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_URSUB8));
  #include "insns/ursub8.h"
  trace_opcode(p,  MATCH_URSUB8, insn);
  #undef xlen
  return npc;
}

reg_t rv64_ursub8(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_URSUB8));
  #include "insns/ursub8.h"
  trace_opcode(p,  MATCH_URSUB8, insn);
  #undef xlen
  return npc;
}
