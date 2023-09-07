
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUADRUPLES 100

struct Quadruple {
    char operand1[10];
    char operand2[10];
    char result[10];
};

struct Quadruple quadruples[MAX_QUADRUPLES];
int quadCount = 0;

void generateQuadruple(const char *op, const char *op1, const char *op2, const char *res) {
    if (quadCount < MAX_QUADRUPLES) {
        strcpy(quadruples[quadCount].operand1, op1);
        strcpy(quadruples[quadCount].operand2, op2);
        strcpy(quadruples[quadCount].result, res);
        quadCount++;
    } else {
        printf("Exceeded maximum quadruple count.\n");
        exit(1);
    }
}

void printQuadruples() {
    printf("Quadruples:\n");
    for (int i = 0; i < quadCount; i++) {
        printf("%d: (%s, %s, %s, %s)\n", i + 1,
                quadruples[i].operand1,
               quadruples[i].operand2, quadruples[i].result);
    }
}

int main() {
    generateQuadruple("+", "a", "b", "t1");
    generateQuadruple("*", "t1", "c", "t2");
    generateQuadruple("-", "t2", "d", "t3");
    generateQuadruple("/", "t3", "e", "result");

    printQuadruples();

    return 0;
}

