// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vdiv_vx(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VDIV_VX));
  #include "insns/vdiv_vx.h"
  trace_opcode(p,  MATCH_VDIV_VX, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vdiv_vx(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VDIV_VX));
  #include "insns/vdiv_vx.h"
  trace_opcode(p,  MATCH_VDIV_VX, insn);
  #undef xlen
  return npc;
}
