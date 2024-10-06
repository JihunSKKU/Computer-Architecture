// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vsuxei16_v(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VSUXEI16_V));
  #include "insns/vsuxei16_v.h"
  trace_opcode(p,  MATCH_VSUXEI16_V, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vsuxei16_v(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VSUXEI16_V));
  #include "insns/vsuxei16_v.h"
  trace_opcode(p,  MATCH_VSUXEI16_V, insn);
  #undef xlen
  return npc;
}
