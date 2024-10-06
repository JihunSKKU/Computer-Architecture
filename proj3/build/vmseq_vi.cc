// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_vmseq_vi(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VMSEQ_VI));
  #include "insns/vmseq_vi.h"
  trace_opcode(p,  MATCH_VMSEQ_VI, insn);
  #undef xlen
  return npc;
}

reg_t rv64_vmseq_vi(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_VMSEQ_VI));
  #include "insns/vmseq_vi.h"
  trace_opcode(p,  MATCH_VMSEQ_VI, insn);
  #undef xlen
  return npc;
}
