#include "instruction.h"

#ifndef VM_H
#define VM_H

typedef struct {
    int max;
    int top;
    DataType *data;
    DataType *variableData;
} Stack;

void run(int **bytes);
void stack_push(Stack *s, DataType value);
DataType *stack_pop(Stack *s);
void stack_store(Stack *s, DataType value, int index);
void stack_load(Stack *s, int index);
Stack create_stack(int size);

#endif