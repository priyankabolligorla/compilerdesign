#include <stdio.h>
#include <string.h>
#define NUM_NON_TERMINALS 3
#define NUM_TERMINALS 3
char nonTerminals[NUM_NON_TERMINALS] = {'E', 'T', 'F'};
char terminals[NUM_TERMINALS] = {'+', '*', 'i'};
char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][5];
void initializeParsingTable() {
    strcpy(parsingTable[0][0], "T");
    strcpy(parsingTable[0][1], "");
    strcpy(parsingTable[0][2], "");
    strcpy(parsingTable[1][0], "");
    strcpy(parsingTable[1][1], "FT'");
    strcpy(parsingTable[1][2], "");
    strcpy(parsingTable[2][0], "");
    strcpy(parsingTable[2][1], "");
    strcpy(parsingTable[2][2], "i");
}
int main() {
    initializeParsingTable();
    printf("Predictive Parsing Table:\n");
    printf("\t+\t*\ti\n");
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        printf("%c\t", nonTerminals[i]);
        for (int j = 0; j < NUM_TERMINALS; j++) {
            if (strlen(parsingTable[i][j]) > 0) {
                printf("%s ", parsingTable[i][j]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
    return 0;
}

