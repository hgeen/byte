#include <stdlib.h>
#include "vm.h"

void run(int **bytes) {

}

Stack create_stack(int size) {
    Stack s;
    s.max = size;
    s.top = 0;
    s.variableData = calloc(size, sizeof(DataType));
    s.data = calloc(size, sizeof(DataType));
    return s;
}

DataType *stack_pop(Stack *s) {

}

void stack_push(Stack *s, DataType value) {

}

void stack_store(Stack *s, DataType value, int index) {

}

void stack_load(Stack *s, int index) {
    
}