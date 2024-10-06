// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vslide1down_vx(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VSLIDE1DOWN_VX));
  #include "insns/vslide1down_vx.h"
  trace_opcode(p,  MATCH_VSLIDE1DOWN_VX, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vslide1down_vx(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VSLIDE1DOWN_VX));
  #include "insns/vslide1down_vx.h"
  trace_opcode(p,  MATCH_VSLIDE1DOWN_VX, insn);
  #undef xlen
  return npc;
}
