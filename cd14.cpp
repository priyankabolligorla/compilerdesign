#include <stdio.h>
int main() {
    char c;
    int spaceCount = 0;
    int newlineCount = 0;
    printf("Enter a text (Ctrl+D or Ctrl+Z to end input):\n");
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            spaceCount++;
        } else if (c == '\n') {
            newlineCount++;
        }
    }
    printf("Number of spaces and tabs: %d\n", spaceCount);
    printf("Number of newline characters: %d\n", newlineCount);
    return 0;
}

