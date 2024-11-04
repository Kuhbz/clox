#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

/**
 * 操作码：控制我们要处理的指令类型——加、减、查找变量等
 */
typedef enum {
    OP_CONSTANT,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN,
} OpCode;

/**
 * 字节码块中:包含了运行时需要从用户源代码中获取的所有信息
 */
typedef struct {
    int count;
    int capacity; // 容量
    uint8_t *code; // 操作码
    int *lines; // 数组中的每个数字都是字节码中对应字节所在的行号
    ValueArray constants; // 常量
} Chunk;

// 初始化块
void initChunk(Chunk *chunk);

// 释放内存
void freeChunk(Chunk *chunk);

// 将一个字节追加到块的末尾
void writeChunk(Chunk *chunk, uint8_t byte, int line);

// 向字节码块中添加一个新常量
int addConstant(Chunk *chunk, Value value);

#endif
