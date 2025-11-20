#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

enum INSTRUCTION{
    ADD,
    SUB,
    MUL,
    DIV,
    INVALID
}; // this is a list of the useable commands

struct Instruction
{
    /* data */
    enum INSTRUCTION instr;
    int operand1;
    int operand2;
}; // this is to show the 3 inputs you have put in and assigns them

//add 20 30

struct Instruction decode(char *sz_instr) {
    struct Instruction inst; //give the structure a variable name to call it with
    inst.instr = INVALID;

    char *token = strtok(sz_instr, " \n"); //strtok() splits a string into tokens
    if (!token) return inst;

    if (strcmp(token, "ADD") == 0) inst.instr = ADD;
    else if (strcmp(token, "SUB") == 0) inst.instr = SUB;
    else if (strcmp(token, "MUL") == 0) inst.instr = MUL;
    else if (strcmp(token, "DIV") == 0) inst.instr = DIV;
    else inst.instr = INVALID;

    // Get the operands that are tokenified now
    token = strtok(NULL, " \t\n");
    inst.operand1 = token ? atoi(token) : 0; //ternary operator: condition ? true : false

    token = strtok(NULL, " \t\n");
    inst.operand2 = token ? atoi(token) : 0;

    return inst;
}

int executeInstruction(struct Instruction inst) { // simple switchcasing to give meaning to the inputs
    switch (inst.instr) {
        case ADD: 
            return inst.operand1 + inst.operand2;
        case SUB: 
            return inst.operand1 - inst.operand2;
        case MUL: 
            return inst.operand1 * inst.operand2;
        case DIV: //division check for 0
            return inst.operand1 / inst.operand2;
        
        default:
            printf("Invalid instruction.\n");
            return 0;
    }
}

void InstructionEngine() {
    char input[100]; //character limit
    printf("Enter instruction to be executed (Add, Sub, Div, Mul) or Exit:\n");

    while (true) { //infinite loop until broken
        printf(" ");
        if (! (fgets(input, sizeof(input), stdin)) ) 
        break;

        if ( strncmp(input, "exit", 4) == 0 ) 
        break;

        struct Instruction inst = decode(input);
        if (inst.instr == INVALID) {
            printf("Unknown instruction.\n");
            continue; 
        }

        int result = executeInstruction(inst);
        printf("Answer = %d\n", result); //operand 1 and 2 should be displayed here also
        printf("Enter instruction to be executed (Add, Sub, Div, Mul) or Exit:\n");

    }
}

int main(int argc, char *argv[])
{   
    InstructionEngine();
    // gcc comLine.c -o comLine <-- this code recompiles it in terminal, use it often!
    return(0);
}

//You need to have header file which declares the functions then have a implementation file which defines those functions for mathematical operations

//Then you have to figure out compiling the math.c, cmdline.c and then link them together to create an executable.

//Read about CMake - then see how you can make use of it for compiling and linking