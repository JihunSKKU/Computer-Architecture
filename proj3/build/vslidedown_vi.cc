// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vslidedown_vi(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VSLIDEDOWN_VI));
  #include "insns/vslidedown_vi.h"
  trace_opcode(p,  MATCH_VSLIDEDOWN_VI, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vslidedown_vi(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VSLIDEDOWN_VI));
  #include "insns/vslidedown_vi.h"
  trace_opcode(p,  MATCH_VSLIDEDOWN_VI, insn);
  #undef xlen
  return npc;
}
