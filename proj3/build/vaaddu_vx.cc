// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vaaddu_vx(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VAADDU_VX));
  #include "insns/vaaddu_vx.h"
  trace_opcode(p,  MATCH_VAADDU_VX, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vaaddu_vx(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VAADDU_VX));
  #include "insns/vaaddu_vx.h"
  trace_opcode(p,  MATCH_VAADDU_VX, insn);
  #undef xlen
  return npc;
}
