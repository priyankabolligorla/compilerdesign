#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    fprintf(file, "Hello, this is a sample text written to the file.\n");
    fprintf(file, "You can write more lines if you'd like!\n");
    fclose(file);
    printf("File created and written successfully.\n");
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("Contents of the file:\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
    return 0;
}

