#include <stdio.h>
#include <string.h>

#define MAX_QUADRUPLES 100

struct Quadruple {

    char operand1[10];
    char operand2[10];
    char result[10];
};

struct Quadruple quadruples[MAX_QUADRUPLES];
int quadCount = 0;

void generateAssembly(const char *op, const char *op1, const char *op2, const char *res) {
    printf("%s %s, %s, %s\n", op, res, op1, op2);
}

void translateQuadruples() {
    for (int i = 0; i < quadCount; i++) {
        struct Quadruple quad = quadruples[i];
            generateAssembly("ADD", quad.operand1, quad.operand2, quad.result);
            generateAssembly("SUB", quad.operand1, quad.operand2, quad.result);
            generateAssembly("MUL", quad.operand1, quad.operand2, quad.result);
            generateAssembly("DIV", quad.operand1, quad.operand2, quad.result);
        }
    }


int main() {
    quadCount = 4;
    strcpy(quadruples[0].operand1, "a");
    strcpy(quadruples[0].operand2, "b");
    strcpy(quadruples[0].result, "t1");
    strcpy(quadruples[1].operand1, "t1");
    strcpy(quadruples[1].operand2, "c");
    strcpy(quadruples[1].result, "t2");
    strcpy(quadruples[2].operand1, "t2");
    strcpy(quadruples[2].operand2, "d");
    strcpy(quadruples[2].result, "t");
    strcpy(quadruples[3].operand1, "t3");
    strcpy(quadruples[3].operand2, "e");
    strcpy(quadruples[3].result, "result");

    translateQuadruples();

    return 0;
}

