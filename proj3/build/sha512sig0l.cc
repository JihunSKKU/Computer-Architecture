// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_sha512sig0l(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_SHA512SIG0L));
  #include "insns/sha512sig0l.h"
  trace_opcode(p,  MATCH_SHA512SIG0L, insn);
  #undef xlen
  return npc;
}

reg_t rv64_sha512sig0l(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_SHA512SIG0L));
  #include "insns/sha512sig0l.h"
  trace_opcode(p,  MATCH_SHA512SIG0L, insn);
  #undef xlen
  return npc;
}
