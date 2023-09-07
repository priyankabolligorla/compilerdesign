#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_RULES 10
#define MAX_SYMBOLS 10
char nonTerminals[MAX_RULES];
char rules[MAX_RULES][MAX_SYMBOLS][MAX_SYMBOLS];
int numRules;
bool hasLeftRecursion(int ruleIndex) {
    return (rules[ruleIndex][0][0] == nonTerminals[ruleIndex]);
}
void eliminateLeftRecursion(int ruleIndex) {
    char newNonTerminal = 'A' + numRules;
    printf("%c -> ", newNonTerminal);
    for (int i = 1; i < MAX_SYMBOLS && rules[ruleIndex][i][0] != '\0'; i++) {
        printf("%s%c' | ", rules[ruleIndex][i], newNonTerminal);
    }
    printf("e\n");
    printf("%c' -> ", newNonTerminal);
    for (int i = 1; i < MAX_SYMBOLS && rules[ruleIndex][i][0] != '\0'; i++) {
        if (rules[ruleIndex][i][0] == nonTerminals[ruleIndex]) {
            printf("%s%c' | ", rules[ruleIndex][i] + 1, newNonTerminal);
        } else {
            printf("%s%c' | ", rules[ruleIndex][i], newNonTerminal);
        }
    }
    printf("e\n");
    numRules++;
}
int main() {
    printf("Enter the number of non-terminals: ");
    scanf("%d", &numRules);
    for (int i = 0; i < numRules; i++) {
        printf("Enter non-terminal %d: ", i + 1);
        scanf(" %c", &nonTerminals[i]);
        printf("Enter number of productions for %c: ", nonTerminals[i]);
        int numProductions;
        scanf("%d", &numProductions);
        printf("Enter productions for %c:\n", nonTerminals[i]);
        for (int j = 0; j < numProductions; j++) {
            scanf("%s", rules[i][j]);
        }
        rules[i][numProductions][0] = '\0';
    }
    printf("Original Grammar:\n");
    for (int i = 0; i < numRules; i++) {
        printf("%c -> ", nonTerminals[i]);
        for (int j = 0; rules[i][j][0] != '\0'; j++) {
            printf("%s | ", rules[i][j]);
        }
        printf("e\n");
    }
    printf("Grammar after Eliminating Left Recursion:\n");
    for (int i = 0; i < numRules; i++) {
        if (hasLeftRecursion(i)) {
            eliminateLeftRecursion(i);
        } else {
            printf("%c -> ", nonTerminals[i]);
            for (int j = 0; rules[i][j][0] != '\0'; j++) {
                printf("%s | ", rules[i][j]);
            }
            printf("e\n");
        }
    }
    return 0;
}

