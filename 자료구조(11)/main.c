#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"


void inputPolynomial(arrayList* al) {
    int n, i;
    elementArrayList item;
    char ch;

    printf("항의 개수 입력: ");
    scanf("%d", &n);
    printf("다항식 입력 (예: 3X^2+2X^1+1X^0): ");

    for (i = 0; i < n; i++) {
        scanf("%dX^%d", &item.coefficient, &item.exponent);
        insertArrayList(al, al->size, item);

        if (i < n - 1)
            scanf("%c", &ch);  
    }
}

void printPolynomial(arrayList* al, char* title) {
    int i;
    elementArrayList item;

    printf("%s: ", title);
    for (i = 0; i < al->size; i++) {
        item = getItemArrayList(al, i);
        if (i > 0) printf("+");
        printf("%dX^%d", item.coefficient, item.exponent);
    }
    printf("\n");
}

void multiplyPolynomial(arrayList* al1, arrayList* al2, arrayList* result) {
    int i, j, k;
    elementArrayList item1, item2, newItem, existing;

    for (i = 0; i < al1->size; i++) {
        item1 = getItemArrayList(al1, i);

        for (j = 0; j < al2->size; j++) {
            item2 = getItemArrayList(al2, j);

            newItem.coefficient = item1.coefficient * item2.coefficient;  // 계수 곱
            newItem.exponent    = item1.exponent + item2.exponent;        // 지수 합

            int found = 0;
            for (k = 0; k < result->size; k++) {
                existing = getItemArrayList(result, k);
                if (existing.exponent == newItem.exponent) {
                    existing.coefficient += newItem.coefficient;
                    replaceItemArrayList(result, k, existing);
                    found = 1;
                    break;
                }
            }

            if (found == 0)
                insertArrayList(result, result->size, newItem);
        }
    }
}

void sortPolynomial(arrayList* al) {
    int i, j;
    elementArrayList a, b;

    for (i = 0; i < al->size - 1; i++) {
        for (j = 0; j < al->size - 1 - i; j++) {
            a = getItemArrayList(al, j);
            b = getItemArrayList(al, j + 1);

            if (a.exponent < b.exponent) {
                replaceItemArrayList(al, j, b);
                replaceItemArrayList(al, j + 1, a);
            }
        }
    }
}

int main() {

    arrayList* al1    = createArrayList(10);
    arrayList* al2    = createArrayList(10);
    arrayList* result = createArrayList(20);

    printf("=== 첫 번째 다항식 ===\n");
    inputPolynomial(al1);

    printf("=== 두 번째 다항식 ===\n");
    inputPolynomial(al2);

    printPolynomial(al1, "다항식 1");
    printPolynomial(al2, "다항식 2");

    multiplyPolynomial(al1, al2, result);

    sortPolynomial(result);

    printPolynomial(result, "곱셈 결과");

    destroyArrayList(al1);
    destroyArrayList(al2);
    destroyArrayList(result);

    return 0;
}