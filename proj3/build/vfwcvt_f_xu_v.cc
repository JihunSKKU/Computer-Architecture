// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vfwcvt_f_xu_v(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VFWCVT_F_XU_V));
  #include "insns/vfwcvt_f_xu_v.h"
  trace_opcode(p,  MATCH_VFWCVT_F_XU_V, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vfwcvt_f_xu_v(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VFWCVT_F_XU_V));
  #include "insns/vfwcvt_f_xu_v.h"
  trace_opcode(p,  MATCH_VFWCVT_F_XU_V, insn);
  #undef xlen
  return npc;
}
