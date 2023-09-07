#include <stdio.h>
#include <string.h>
#define MAX_RULES 10
#define MAX_SYMBOLS 10
char nonTerminal;
char rules[MAX_RULES][MAX_SYMBOLS][MAX_SYMBOLS];
int numRules;
void eliminateLeftFactoring(int ruleIndex) {
    char commonPrefix[MAX_SYMBOLS];
    int prefixLength = 0;
    int maxPrefixLength = 0;
    for (int i = 0; rules[ruleIndex][i][0] != '\0'; i++) {
        for (int j = 0; j < i; j++) {
            prefixLength = 0;
            while (rules[ruleIndex][i][prefixLength] == rules[ruleIndex][j][prefixLength]) {
                prefixLength++;
            }
            if (prefixLength > maxPrefixLength) {
                maxPrefixLength = prefixLength;
                strcpy(commonPrefix, rules[ruleIndex][i]);
                commonPrefix[prefixLength] = '\0';
            }
        }
    }
    if (maxPrefixLength > 0) {
        printf("Common prefix: %s\n", commonPrefix);
        char newNonTerminal = 'A' + numRules;
        printf("%c -> %s%c'\n", nonTerminal, commonPrefix, newNonTerminal);
        printf("%c' -> ", newNonTerminal);
        for (int i = 0; rules[ruleIndex][i][0] != '\0'; i++) {
            if (strncmp(rules[ruleIndex][i], commonPrefix, maxPrefixLength) == 0) {
                printf("%s | ", rules[ruleIndex][i] + maxPrefixLength);
            }
        }
        printf("e\n");
        numRules++;
    }
}
int main() {
    printf("Enter the non-terminal: ");
    scanf(" %c", &nonTerminal);
    printf("Enter the number of productions: ");
    scanf("%d", &numRules);
    for (int i = 0; i < numRules; i++) {
        printf("Enter production %d: ", i + 1);
        scanf("%s", rules[i][0]);
    }
    printf("Original Productions:\n");
    for (int i = 0; i < numRules; i++) {
        printf("%c -> %s\n", nonTerminal, rules[i][0]);
    }
    printf("Productions after Eliminating Left Factoring:\n");
    for (int i = 0; i < numRules; i++) {
        eliminateLeftFactoring(i);
    }
    return 0;
}

