#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
struct Symbol 
{
    char name[20];
    int value;
};
struct SymbolTable 
{
    struct Symbol* table[SIZE];
};
unsigned int hash(char* str) 
{
    unsigned int hash = 0;
    while (*str) 
	{
        hash = (hash << 5) + *str++;
    }
    return hash % SIZE;
}
struct Symbol* createSymbol(char* name, int value) 
{
    struct Symbol* symbol = (struct Symbol*)malloc(sizeof(struct Symbol));
    strcpy(symbol->name, name);
    symbol->value = value;
    return symbol;
}
void insert(struct SymbolTable* st, char* name, int value) 
{
    unsigned int index = hash(name);
    struct Symbol* symbol = createSymbol(name, value);
    st->table[index] = symbol;
}
struct Symbol* search(struct SymbolTable* st, char* name) 
{
    unsigned int index = hash(name);
    return st->table[index];
}
int main() 
{
    struct SymbolTable symbolTable;
    for (int i = 0; i < SIZE; i++) 
	{
        symbolTable.table[i] = NULL;
    }

    insert(&symbolTable, "x", 10);
    insert(&symbolTable, "y", 20);
    insert(&symbolTable, "z", 30);
    char searchName[20];
    printf("Enter symbol name to search: ");
    scanf("%s", searchName);
    struct Symbol* foundSymbol = search(&symbolTable, searchName);
    if (foundSymbol) {
        printf("Symbol found: %s = %d\n", foundSymbol->name, foundSymbol->value);
    } else {
        printf("Symbol not found.\n");
    }
    return 0;
}

