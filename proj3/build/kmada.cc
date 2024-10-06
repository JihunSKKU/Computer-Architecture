// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_kmada(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_KMADA));
  #include "insns/kmada.h"
  trace_opcode(p,  MATCH_KMADA, insn);
  #undef xlen
  return npc;
}

reg_t rv64_kmada(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_KMADA));
  #include "insns/kmada.h"
  trace_opcode(p,  MATCH_KMADA, insn);
  #undef xlen
  return npc;
}
