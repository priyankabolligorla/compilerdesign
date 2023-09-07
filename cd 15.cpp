#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define STACK_SIZE 100
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
void infixToPostfix(char *infix, char *postfix) {
    char stack[STACK_SIZE];
    int top = -1;
    int postfixIndex = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
            postfix[postfixIndex++] = c;
            stack[++top] = 
            top--; 
            while (top >= 0 && precedence(stack[top]) >= precedence(c)) {
                postfix[postfixIndex++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

int main() {
    char infix[STACK_SIZE];
    char postfix[STACK_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

