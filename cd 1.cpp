#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isComment(char *input) 
{
    if (strncmp(input, "//", 2) == 0) 
	{
        return true;
    }
    int len = strlen(input);
    if (len >= 4 && input[0] == '/' && input[1] == '*' && input[len - 2] == '*' && input[len - 1] == '/') {
        return true;
    }
    return false;
}
int main() 
{
    char input[100];
    printf("Enter a line of text: ");
    fgets(input, sizeof(input), stdin);
    if (isComment(input)) {
        printf("The input is a comment.\n");
    } else 
	{
        printf("The input is not a comment.\n");
    }
    return 0;
}

