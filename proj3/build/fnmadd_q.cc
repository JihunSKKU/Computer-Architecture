// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_fnmadd_q(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FNMADD_Q));
  #include "insns/fnmadd_q.h"
  trace_opcode(p,  MATCH_FNMADD_Q, insn);
  #undef xlen
  return npc;
}

reg_t rv64_fnmadd_q(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FNMADD_Q));
  #include "insns/fnmadd_q.h"
  trace_opcode(p,  MATCH_FNMADD_Q, insn);
  #undef xlen
  return npc;
}
