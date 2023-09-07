#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
char input[100];
int position = 0;
bool E();
bool T();
bool F();
bool match(char expected) {
    if (input[position] == expected) {
        position++;
        return true;
    }
    return false;
}
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
bool E() {
    if (T()) {
        while (input[position] == '+' || input[position] == '-') {
            char op = input[position];
            position++;
            if (!T()) {
                return false;
            }
            printf("%c ", op);
        }
        return true;
    }
    return false;
}
bool T() {
    if (F()) {
        while (input[position] == '*' || input[position] == '/') {
            char op = input[position];
            position++;
            if (!F()) {
                return false;
            }
            printf("%c ", op);
        }
        return true;
    }
    return false;
}
bool F() {
    if (isdigit(input[position])) {
        printf("%c ", input[position]);
        position++;
        return true;
    } else if (input[position] == '(') {
        position++;
        if (E()) {
            if (input[position] == ')') {
                position++;
                return true;
            }
        }
    }
    return false;
}
int main() {
    printf("Enter an arithmetic expression: ");
    scanf("%s", input);

    if (E() && input[position] == '\0') {
        printf("Valid arithmetic expression!\n");
    } else {
        printf("Invalid arithmetic expression!\n");
    }
    return 0;
}
 
