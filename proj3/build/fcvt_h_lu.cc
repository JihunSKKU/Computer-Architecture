// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_fcvt_h_lu(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FCVT_H_LU));
  #include "insns/fcvt_h_lu.h"
  trace_opcode(p,  MATCH_FCVT_H_LU, insn);
  #undef xlen
  return npc;
}

reg_t rv64_fcvt_h_lu(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FCVT_H_LU));
  #include "insns/fcvt_h_lu.h"
  trace_opcode(p,  MATCH_FCVT_H_LU, insn);
  #undef xlen
  return npc;
}
