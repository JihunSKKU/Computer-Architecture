// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_uclip8(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_UCLIP8));
  #include "insns/uclip8.h"
  trace_opcode(p,  MATCH_UCLIP8, insn);
  #undef xlen
  return npc;
}

reg_t rv64_uclip8(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_UCLIP8));
  #include "insns/uclip8.h"
  trace_opcode(p,  MATCH_UCLIP8, insn);
  #undef xlen
  return npc;
}
