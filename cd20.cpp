
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool S();
bool T();
char input[100];
int position = 0;
bool isAmbiguous = false;
bool match(char c) {
    if (input[position] == c) {
        position++;
        return true;
    }
    return false;
}
bool S() {
    int initialPosition = position;
    if (T() && match('+') && T()) {
        if (input[position] == '\0') {
            isAmbiguous = true;
            return true;
        }
    }
    position = initialPosition;
    return false;
}
bool T() {
    int initialPosition = position;
    if (match('i')) {
        if (input[position] == '\0') {
            isAmbiguous = true;
            return true;
        }
    }
    if (match('(') && S() && match(')')) {
        if (input[position] == '\0') {
            isAmbiguous = true;
            return true;
        }
    }
    position = initialPosition;
    return false;
}
int main() {
    printf("Enter an input string: ");
    scanf("%s", input);
    if (S() && input[position] == '\0') {
        if (isAmbiguous) {
            printf("Grammar is ambiguous.\n");
        } else {
            printf("Grammar is not ambiguous.\n");
        }
    } else {
        printf("Invalid input string.\n");
    }
    return 0;
}

