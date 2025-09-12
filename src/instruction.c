#include <stdlib.h>
#include <string.h>
#include "instruction.h"

int get_parameters(char **buffer, FILE *file) {
    char c = 0;
    char *param = malloc(sizeof(char*));
    int index = 0;

    while ((c = fgetc(file)) != EOF && c != '\n') {
        if (c == ' ') {
            index++;
            continue;
        }

        
    };

    

    return (c == 0) ? 1 : 0;
}

Instruction *generate_instructions(FILE *file) {
    Instruction *instructions = calloc(1, sizeof(Instruction));
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
            
            if (strcmp(token, "PUSHINT") == 0) {

            } else if (strcmp(token, "PUSHFLOAT") == 0) {

            } else if (strcmp(token, "PUSHCHAR") == 0) {

            } else if (strcmp(token, "PUSHSTR") == 0) {

            } else if (strcmp(token, "ADD") == 0) {
                
            } else if (strcmp(token, "SUB") == 0) {

            } else if (strcmp(token, "MULT") == 0) {

            }

            free(token);
            token = calloc(64, sizeof(char*));
        } else {
            token[tok_i++] = c;
        }
    };
}