#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 100

char input[100];
char stack[MAX_STACK_SIZE];
int stackTop = -1;
int position = 0;

void push(char c) {
    if (stackTop < MAX_STACK_SIZE - 1) {
        stack[++stackTop] = c;
    }
}

char pop() {
    if (stackTop >= 0) {
        return stack[stackTop--];
    }
    return '\0';
}

bool reduce() {
    char temp[100];
    strcpy(temp, stack);
    char *ptr = strstr(temp, "ab");
    if (ptr != NULL) {
        ptr[0] = 'S';
        ptr[1] = '\0';
        strcpy(stack, temp);
        stackTop = strlen(stack) - 1;
        return true;
    }
    return false;
}

void shift() {
    push(input[position++]);
}

bool parse() {
    while (position <= strlen(input)) {
        if (reduce()) {
            printf("Reduce: %s\n", stack);
        } else {
            shift();
            printf("Shift: %s\n", stack);
        }
    }

    return strcmp(stack, "S") == 0;
}

int main() {
    printf("Enter an input string: ");
    scanf("%s", input);

    stackTop = -1;
    push('$');
    printf("Stack: %s\n", stack);

    if (parse()) {
        printf("Parsing successful!\n");
    } else {
        printf("Parsing failed.\n");
    }

    return 0;
}


