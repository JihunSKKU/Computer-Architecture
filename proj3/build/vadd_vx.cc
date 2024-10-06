// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vadd_vx(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VADD_VX));
  #include "insns/vadd_vx.h"
  trace_opcode(p,  MATCH_VADD_VX, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vadd_vx(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VADD_VX));
  #include "insns/vadd_vx.h"
  trace_opcode(p,  MATCH_VADD_VX, insn);
  #undef xlen
  return npc;
}
