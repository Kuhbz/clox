#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"
#define STACK_MAX 256

typedef struct {
    Chunk *chunk;
    uint8_t* ip; // 当前执行的指令的下一条指令所在的位置,ip总是指向下一条指令，而不是当前正在处理的指令
    Value stack[STACK_MAX];
    Value* stackTop; // 指向数组中栈顶元素的下一个元素位置
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();

void freeVM();

InterpretResult interpret(Chunk *chunk);

void push(Value value);
Value pop();

#endif
