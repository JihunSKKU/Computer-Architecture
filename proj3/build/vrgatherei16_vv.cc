// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vrgatherei16_vv(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VRGATHEREI16_VV));
  #include "insns/vrgatherei16_vv.h"
  trace_opcode(p,  MATCH_VRGATHEREI16_VV, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vrgatherei16_vv(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VRGATHEREI16_VV));
  #include "insns/vrgatherei16_vv.h"
  trace_opcode(p,  MATCH_VRGATHEREI16_VV, insn);
  #undef xlen
  return npc;
}
