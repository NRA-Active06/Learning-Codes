#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include "math.h"
#include "cmdline.h"

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

struct Instruction decode(char *sz_instr) {
    struct Instruction inst; //give the structure a variable name to call it with
    inst.instr = INVALID;

    char *token = NULL;
    token = strtok(sz_instr, " \n"); //strtok() splits a string into tokens
    if (!token) return inst;

    for (char *p = token; *p; ++p) *p = toupper((unsigned char)*p); //capitalise

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
            return amini_add(inst.operand1, inst.operand2);
        case SUB:
            return amini_sub(inst.operand1, inst.operand2);
        case MUL:
            return amini_mul(inst.operand1, inst.operand2);
        case DIV:
            return amini_div(inst.operand1, inst.operand2);
        default:
            printf("Invalid instruction.\n");
            return 0;
    }
}


void run_cmdline(int argc, char *argv[]) {

    char input[100]; //character limit
    printf("Enter instruction to be executed (Add, Sub, Div, Mul) or Exit:\n");

    while (1) { //infinite loop until broken
        printf(" ");
        if (!fgets(input, sizeof(input), stdin) ) //flush out command line
            break;

        if ( strncasecmp(input, "exit", 4) == 0 ) 
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