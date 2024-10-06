// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vmv_v_i(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VMV_V_I));
  #include "insns/vmv_v_i.h"
  trace_opcode(p,  MATCH_VMV_V_I, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vmv_v_i(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VMV_V_I));
  #include "insns/vmv_v_i.h"
  trace_opcode(p,  MATCH_VMV_V_I, insn);
  #undef xlen
  return npc;
}
