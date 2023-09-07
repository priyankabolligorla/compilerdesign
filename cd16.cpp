#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INSTRUCTIONS 100
struct Instruction {
    char operation[10];
    char operand1[10];
    char operand2[10];
    char result[10];
};
struct Instruction instructions[MAX_INSTRUCTIONS];
int instructionCount = 0;
void optimizeCommonSubexpressions() {
    for (int i = 0; i < instructionCount; i++) {
        for (int j = i + 1; j < instructionCount; j++) {
            if (strcmp(instructions[i].operation, instructions[j].operation) == 0 &&
                strcmp(instructions[i].operand1, instructions[j].operand1) == 0 &&
                strcmp(instructions[i].operand2, instructions[j].operand2) == 0) {
                // Replace the common subexpression with the result of the first occurrence
                strcpy(instructions[j].operation, "COPY");
                strcpy(instructions[j].operand1, instructions[i].result);
            }
        }
    }
}
int main() {
    strcpy(instructions[0].operation, "ADD");
    strcpy(instructions[0].operand1, "a");
    strcpy(instructions[0].operand2, "b");
    strcpy(instructions[0].result, "t1");
    strcpy(instructions[1].operation, "ADD");
    strcpy(instructions[1].operand1, "a");
    strcpy(instructions[1].operand2, "b");
    strcpy(instructions[1].result, "t2");
    strcpy(instructions[2].operation, "SUB");
    strcpy(instructions[2].operand1, "t1");
    strcpy(instructions[2].operand2, "c");
    strcpy(instructions[2].result, "t3");
    instructionCount = 3;
    printf("Original Instructions:\n");
    for (int i = 0; i < instructionCount; i++) {
        printf("%s %s, %s, %s\n",
               instructions[i].operation, instructions[i].result,
               instructions[i].operand1, instructions[i].operand2);
    }
    optimizeCommonSubexpressions();
    printf("\nInstructions after Common Subexpression Elimination:\n");
    for (int i = 0; i < instructionCount; i++) {
        printf("%s %s, %s, %s\n",
               instructions[i].operation, instructions[i].result,
               instructions[i].operand1, instructions[i].operand2);
    }
    return 0;
}

