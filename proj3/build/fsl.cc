// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_fsl(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FSL));
  #include "insns/fsl.h"
  trace_opcode(p,  MATCH_FSL, insn);
  #undef xlen
  return npc;
}

reg_t rv64_fsl(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FSL));
  #include "insns/fsl.h"
  trace_opcode(p,  MATCH_FSL, insn);
  #undef xlen
  return npc;
}
