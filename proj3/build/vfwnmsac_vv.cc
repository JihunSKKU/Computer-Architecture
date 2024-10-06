// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vfwnmsac_vv(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VFWNMSAC_VV));
  #include "insns/vfwnmsac_vv.h"
  trace_opcode(p,  MATCH_VFWNMSAC_VV, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vfwnmsac_vv(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VFWNMSAC_VV));
  #include "insns/vfwnmsac_vv.h"
  trace_opcode(p,  MATCH_VFWNMSAC_VV, insn);
  #undef xlen
  return npc;
}
