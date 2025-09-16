#include <stdio.h>

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef enum {
    OP_PUSHINT = 0x00,
    OP_PUSHFLOAT = 0x01,
    OP_PUSHCHAR = 0x02,
    OP_PUSHSTR = 0x03,
    OP_ADD = 0x04,
    OP_SUB = 0x05,
    OP_MULT = 0x06,
    OP_DIV = 0x07,
    OP_EXP = 0x08,
    OP_STORE = 0x09,
    OP_LOAD = 0x0a,
    OP_STACKALLOC = 0x0b,
    OP_STACKDEALLOC  = 0x0c,
    OP_DELETE = 0x0d,
    OP_PRINT = 0x0f,
    OP_JUMP = 0x10,
    OP_IF = 0x11,
    OP_FUNCTION = 0x12,
    OP_LABEL = 0x13,
    OP_ENDDEF = 0x14,
    //GETGLOBAL = 0x09,
} BytecodeInstruction;

typedef struct {

} Instruction;

typedef enum {
    VAL_INT,
    VAL_FLOAT,
    VAL_CHAR,
    VAL_STRING,
} Value;

typedef union {
    int i;
    float f;
    char c;
    char *s;
} Data;

typedef struct {
    Value type;
    Data data;
} DataType;

int get_parameters(char **buffer, FILE *file);
Instruction *generate_instructions(FILE *file);
int **generate_bytecode(Instruction *instructions);

#endif