#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

// 反汇编整个字节码块中的所有指令
void disassembleChunk(Chunk* chunk, const char* name);

// 只反汇编一条指令
int disassembleInstruction(Chunk* chunk, int offset);

#endif