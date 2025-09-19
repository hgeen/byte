#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "instruction.h"

#define END_OF_BUFFER (char*) -1

static EXIT_CODE text_to_int(char *text, int *buffer) {
    int i = 0;
    char c = 0;
    char sign = 1;
    int result = 0;

    if (text[0] == '-') {
        sign = -1;
        i = 1;
    }

    while ((c = text[i++]) != '\n') {
        if (c - '0' > 9 || c - '0' < 0) {
            return FAIL;
        }

        result = result * 10 + (c - '0');
    }

    // i assume this sets the value of buffer to result
    *buffer = result;

    return SUCCESS;
}

static EXIT_CODE text_to_float(char *text, float *buffer) {
    int i = 0;
    char c = 0;
    char sign = 1;
    int result = 0;
    int fraction = 0;
    int factor = 1;
    char decimal = 0;

    if (text[0] == '-') {
        sign = -1;
        i = 1;
    }

    while ((c = text[i++]) != '\n') {
        if (c - '0' > 9 || c - '0' < 0) {
            return FAIL;
        }

        if (c == '.') {
            decimal = 1;
        }

        result = result * 10 + (c - '0');
    }

    if (decimal) {
        while ((c = text[i++]) != '\n') {
            if (c - '0' > 9 || c - '0' < 0) {
                return FAIL;
            }

            fraction = result * 10 + (c - '0');
            factor *= 10;
        }
        
        *buffer = (float) result + ((float) fraction / factor);

        return SUCCESS;
    }

    *buffer = (float) result;

    return SUCCESS;
}

int get_parameters(char **buffer, FILE *file) {
    char c = 0;
    char *param = malloc(sizeof(char*));
    int index = 0;
    int param_i = 0;

    while ((c = fgetc(file)) != EOF && c != '\n') {
        if (c == ' ') {
            if (!strcmp(param, "")) {
                param[param_i] = '\n';
                param_i = 0;
                buffer[index++] = param; 
            }
            continue;
        }

        param[param_i++] = c;
    };

    buffer[index] = END_OF_BUFFER;

    return (c == 0) ? 1 : 0;
}

Instruction *generate_instructions(FILE *file) {
    int sz = 256;
    Instruction *instructions = calloc(sz, sizeof(Instruction));
    char *token = calloc(64, sizeof(char*));
    char c = 0;
    int comments = 0;
    int param_i = 0;
    int tok_i = 0;

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            if (tok_i == 0) continue;

            token[tok_i] = '\0';
            tok_i = 0;

            if (param_i > sz) {
                instructions = realloc(&instructions, 2 * sz);
            }
            
            if (strcmp(token, "PUSHINT") == 0) {
                Instruction i;
                i.instruction = OP_PUSHINT;
                char **parameters;

                if (get_parameters(parameters, file)) {
                    int n = 0;

                    text_to_int(parameters[0], &n);

                    Object o;
                    o.d.type = VAL_INT;
                    o.d.data.i = n;
                    i.parameters[0] = o;
                    instructions[param_i++] = i;
                } else {
                    //assert(0 == 1);
                }

                //instructions[]
            } else if (strcmp(token, "PUSHFLOAT") == 0) {
                Instruction i;
                i.instruction = OP_PUSHFLOAT;
                char **parameters;

                if (get_parameters(parameters, file)) {
                    float n = 0;

                    text_to_float(parameters[0], &n);

                    Object o;
                    o.d.type = VAL_FLOAT;
                    o.d.data.f = n;
                    i.parameters[0] = o;
                    instructions[param_i++] = i;
                } else {
                    //assert(0 == 1);
                }
            } else if (strcmp(token, "PUSHCHAR") == 0) {
                Instruction i;
                i.instruction = OP_PUSHCHAR;
                char **parameters;

                if (get_parameters(parameters, file)) {
                    float n = 0;

                    Object o;
                    o.d.type = VAL_CHAR;
                    o.d.data.c = n;
                    i.parameters[0] = o;
                    instructions[param_i++] = i;
                } else {
                    //assert(0 == 1);
                }
            } else if (strcmp(token, "PUSHSTR") == 0) {

            } else if (strcmp(token, "ADD") == 0) {
                Instruction i;
                i.instruction = OP_ADD;
            } else if (strcmp(token, "SUB") == 0) {
                Instruction i;
                i.instruction = OP_SUB;
                instructions[param_i++] = i;
            } else if (strcmp(token, "MULT") == 0) {
                Instruction i;
                i.instruction = OP_MULT;
                instructions[param_i++] = i;
            } else if (strcmp(token, "DIV") == 0) {
                Instruction i;
                i.instruction = OP_DIV;
                instructions[param_i++] = i;
            }
            
            free(token);
            token = calloc(64, sizeof(char*));
        } else {
            token[tok_i++] = c;
        }
    };

    Instruction end;
    end.instruction = OP_END;

    instructions[param_i] = end;
    return instructions;
}

int *instruction_to_bytecode(Instruction *instructions) {
    int i = 0;
    int sz = 256;
    int *bytecodes = calloc(sz, sizeof(int));
    Instruction ins;

    while ((ins = instructions[i++]).instruction != OP_END) {

    }
}