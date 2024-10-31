#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double Value;
// 常量池
typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
// 打印常量值
void printValue(Value value);


#endif