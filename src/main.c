#include <stdio.h>
#include <windows.h>
#include <direct.h>

#include "instruction.h"
#include "vm.h"

int main(int argc, char **argv) {
    if (argc == 0)
        return -1;

    //char cwd[1024];
    //char buffer[256];

    //_getcwd(cwd, sizeof(cwd));

    //printf("%s\n", cwd);

    //printf("%s\n", argv[1]);

    //fgets(buffer, sizeof(buffer), test);

    //printf("%s", buffer);

    //WIN32_FIND_DATA fileData;
    //DWORD path;
    //HANDLE 

    FILE *file = fopen(argv[1], "r");

    //Instruction *instructions = generate_instructions(file);
    //int **bytes = generate_bytecode(instructions);
    //run(bytes);
}