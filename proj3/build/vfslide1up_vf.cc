// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vfslide1up_vf(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VFSLIDE1UP_VF));
  #include "insns/vfslide1up_vf.h"
  trace_opcode(p,  MATCH_VFSLIDE1UP_VF, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vfslide1up_vf(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VFSLIDE1UP_VF));
  #include "insns/vfslide1up_vf.h"
  trace_opcode(p,  MATCH_VFSLIDE1UP_VF, insn);
  #undef xlen
  return npc;
}
