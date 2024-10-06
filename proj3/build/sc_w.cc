// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_sc_w(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_SC_W));
  #include "insns/sc_w.h"
  trace_opcode(p,  MATCH_SC_W, insn);
  #undef xlen
  return npc;
}

reg_t rv64_sc_w(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_SC_W));
  #include "insns/sc_w.h"
  trace_opcode(p,  MATCH_SC_W, insn);
  #undef xlen
  return npc;
}
