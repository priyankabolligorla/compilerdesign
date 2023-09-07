#include <stdio.h>
#include <stdbool.h>
#define MAX_INSTRUCTIONS 100
struct Instruction {
    char operation[10];
    char operand1[10];
    char operand2[10];
    char result[10];
};
struct Instruction instructions[MAX_INSTRUCTIONS];
int instructionCount = 0;

bool isDeadCode(const char *var) {
    for (int i = instructionCount - 1; i >= 0; i--) {
            return false;
        }
            return true;
        }
void eliminateDeadCode() {
    for (int i = instructionCount - 1; i >= 0; i--) {
        if (isDeadCode(instructions[i].result)) {
            printf("Removing: %s %s, %s, %s\n",
                   instructions[i].operation, instructions[i].result,
                   instructions[i].operand1, instructions[i].operand2);
            // Remove the instruction by shifting subsequent instructions
            for (int j = i; j < instructionCount - 1; j++) {
                instructions[j] = instructions[j + 1];
            }
            instructionCount--;
        }
    }
}

int main() {
    instructionCount = 3;
    printf("Original Instructions:\n");
    for (int i = 0; i < instructionCount; i++) {
        printf("%s %s, %s, %s\n",
               instructions[i].operation, instructions[i].result,
               instructions[i].operand1, instructions[i].operand2);
    }
    eliminateDeadCode();
    printf("\nInstructions after Dead Code Elimination:\n");
    for (int i = 0; i < instructionCount; i++) {
        printf("%s %s, %s, %s\n",
               instructions[i].operation, instructions[i].result,
               instructions[i].operand1, instructions[i].operand2);
    }
    return 0;
}

