// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_fmv_h_x(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FMV_H_X));
  #include "insns/fmv_h_x.h"
  trace_opcode(p,  MATCH_FMV_H_X, insn);
  #undef xlen
  return npc;
}

reg_t rv64_fmv_h_x(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FMV_H_X));
  #include "insns/fmv_h_x.h"
  trace_opcode(p,  MATCH_FMV_H_X, insn);
  #undef xlen
  return npc;
}
