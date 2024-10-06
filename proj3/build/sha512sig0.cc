// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

reg_t rv32_sha512sig0(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  reg_t npc = sext_xlen(pc + insn_length( MATCH_SHA512SIG0));
  #include "insns/sha512sig0.h"
  trace_opcode(p,  MATCH_SHA512SIG0, insn);
  #undef xlen
  return npc;
}

reg_t rv64_sha512sig0(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  reg_t npc = sext_xlen(pc + insn_length( MATCH_SHA512SIG0));
  #include "insns/sha512sig0.h"
  trace_opcode(p,  MATCH_SHA512SIG0, insn);
  #undef xlen
  return npc;
}
