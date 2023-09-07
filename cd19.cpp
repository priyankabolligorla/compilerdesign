#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STATES 10
#define MAX_SYMBOLS 5
char grammar[MAX_STATES][MAX_SYMBOLS][20] = {
    {"S'", "S", "", "", ""},
    {"S", "E", "", "", ""},
    {"E", "E+T", "T", "", ""},
    {"E", "T", "", "", ""},
    {"T", "T*F", "F", "", ""},
    {"T", "F", "", "", ""},
    {"F", "(E)", "", "", ""},
    {"F", "id", "", "", ""}
};
char nonTerminals[] = "SETF";
char terminals[] = "+*()id";
char parsingTable[MAX_STATES][MAX_SYMBOLS][2];
int numStates = 7;
void initializeParsingTable() {
    strcpy(parsingTable[0][0], "s2");
    strcpy(parsingTable[0][4], "1");
    strcpy(parsingTable[1][1], "s3");
    strcpy(parsingTable[1][2], "s4");
    strcpy(parsingTable[2][1], "r2");
    strcpy(parsingTable[2][2], "r2");
    strcpy(parsingTable[2][3], "s5");
    strcpy(parsingTable[2][4], "r2");
    strcpy(parsingTable[3][1], "r4");
    strcpy(parsingTable[3][2], "r4");
    strcpy(parsingTable[3][3], "r4");
    strcpy(parsingTable[3][4], "r4");
    strcpy(parsingTable[4][0], "s6");
    strcpy(parsingTable[4][4], "r6");
    strcpy(parsingTable[5][0], "r5");
    strcpy(parsingTable[5][1], "s3");
    strcpy(parsingTable[5][2], "s4");
    strcpy(parsingTable[5][3], "r5");
    strcpy(parsingTable[5][4], "r5");
    strcpy(parsingTable[6][0], "r7");
    strcpy(parsingTable[6][1], "r7");
    strcpy(parsingTable[6][2], "r7");
    strcpy(parsingTable[6][3], "r7");
    strcpy(parsingTable[6][4], "r7");
}
int findSymbolIndex(char symbol) {
    if (strchr(nonTerminals, symbol) != NULL) {
        return symbol - 'A';
    } else if (strchr(terminals, symbol) != NULL) {
        return (symbol - 'a') + strlen(nonTerminals);
    }
    return -1;
}
void parseInput(char input[]) {
    char stack[100];
    int top = 0;
    int state = 0;
    stack[top++] = '0';
    int inputIndex = 0;
    while (input[inputIndex] != '\0') {
        int symbolIndex = findSymbolIndex(input[inputIndex]);
        if (symbolIndex == -1) {
            printf("Invalid input symbol: %c\n", input[inputIndex]);
            return;
        }
        char action[3];
        strcpy(action, parsingTable[state][symbolIndex]);

        if (action[0] == 's') {
            state = action[1] - '0';
            stack[top++] = input[inputIndex];
            stack[top++] = action[1];
            inputIndex++;
        } else if (action[0] == 'r') {
            int ruleIndex = action[1] - '0';
            int numSymbols = strlen(grammar[ruleIndex][1]);

            for (int i = 0; i < numSymbols * 2; i++) {
                top--;
            }

            int newState = stack[top - 1] - '0';
            stack[top++] = grammar[ruleIndex][0][0];
            stack[top++] = parsingTable[newState][grammar[ruleIndex][0][0] - 'A'][0];

            state = newState;
        } else if (strcmp(action, "accept") == 0) {
            printf("Input is accepted.\n");
            return;
        } else {
            printf("Syntax error.\n");
            return;
        }
    }
    printf("Input is not accepted.\n");
}
int main() {
    initializeParsingTable();
    char input[100];
    printf("Enter an input string: ");
    scanf("%s", input);
    parseInput(input);
    return 0;
}

