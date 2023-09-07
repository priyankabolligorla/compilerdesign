#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TRIPLES 100
struct Triple {
    char operand1[10];
    char operand2[10];
};
struct Triple triples[MAX_TRIPLES];
int tripleCount = 0;
void generateTriple(const char *op, const char *op1, const char *op2) {
    if (tripleCount < MAX_TRIPLES) {
        strcpy(triples[tripleCount].operand1, op1);
        strcpy(triples[tripleCount].operand2, op2);
        tripleCount++;
    } else {
        printf("Exceeded maximum triple count.\n");
        exit(1);
    }
}
void printTriples() {
    printf("Triples:\n");
    for (int i = 0; i < tripleCount; i++) {
        printf("(%s, %s, %s)\n",
                triples[i].operand1, triples[i].operand2);
    }
}
int main() {
    generateTriple("+", "a", "b");
    generateTriple("*", "t1", "c");
    generateTriple("-", "t2", "d");
    generateTriple("/", "t3", "e");
    printTriples();
    return 0;
}

