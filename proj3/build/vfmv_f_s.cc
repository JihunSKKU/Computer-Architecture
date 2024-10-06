// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vfmv_f_s(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VFMV_F_S));
  #include "insns/vfmv_f_s.h"
  trace_opcode(p,  MATCH_VFMV_F_S, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vfmv_f_s(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VFMV_F_S));
  #include "insns/vfmv_f_s.h"
  trace_opcode(p,  MATCH_VFMV_F_S, insn);
  #undef xlen
  return npc;
}
