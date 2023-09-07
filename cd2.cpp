#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
bool isOperator(char ch) {
    char operators[] = "+-*/%";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i]) {
            return true;
        }
    }
    return false;
}
bool isIdentifier(char *token) {
    if (!isalpha(token[0])) {
        return false;
    }
    for (int i = 1; i < strlen(token); i++) {
        if (!isalnum(token[i])) {
            return false;
        }
    }
    return true;
}
bool isConstant(char *token) {
    for (int i = 0; i < strlen(token); i++) {
        if (!isdigit(token[i])) {
            return false;
        }
    }
    return true;
}
int main() 
{
    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    char delimiters[] = " \t\n";
    char *token = strtok(expression, delimiters);
    while (token != NULL) 
	{
        if (isOperator(token[0])) {
            printf("Operator: %s\n", token);
        } else if (isIdentifier(token)) {
            printf("Identifier: %s\n", token);
        } else if (isConstant(token)) {
            printf("Constant: %s\n", token);
        } else {
            printf("Unknown token: %s\n", token);
        }
        token = strtok(NULL, delimiters);
    }
    return 0;
}

