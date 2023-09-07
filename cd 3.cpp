#include <stdio.h>
#include <stdbool.h>
int main()  
{
    char c, prev = '\0';
    bool inComment = false;
    printf("Enter C code (Ctrl+D to end):\n");
    while ((c = getchar()) != EOF) 
	{
        if (inComment) 
		{
            if (prev == '*' && c == '/') 
			{
                inComment = false;
            }
        } else {
            if (c == '/' && prev == '/') 
			{
            
                while ((c = getchar()) != EOF && c != '\n');
            } else if (c == '*' && prev == '/') 
			{
                
                inComment = true;
            } else if (c != ' ' && c != '\t') 
			{
            	
                putchar(c);
            }
        }
        prev = c;
    }
    return 0;
}

