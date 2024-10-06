// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_fsub_q(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FSUB_Q));
  #include "insns/fsub_q.h"
  trace_opcode(p,  MATCH_FSUB_Q, insn);
  #undef xlen
  return npc;
}

reg_t rv64_fsub_q(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FSUB_Q));
  #include "insns/fsub_q.h"
  trace_opcode(p,  MATCH_FSUB_Q, insn);
  #undef xlen
  return npc;
}
