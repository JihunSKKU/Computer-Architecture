// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_fcvt_q_l(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FCVT_Q_L));
  #include "insns/fcvt_q_l.h"
  trace_opcode(p,  MATCH_FCVT_Q_L, insn);
  #undef xlen
  return npc;
}

reg_t rv64_fcvt_q_l(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FCVT_Q_L));
  #include "insns/fcvt_q_l.h"
  trace_opcode(p,  MATCH_FCVT_Q_L, insn);
  #undef xlen
  return npc;
}
