#include <stdio.h>
#include <stdlib.h>
#include "sparseMatrix.h"

sparseMatrix* createSparseMatrix(int row, int col) {
    return createArrayList(row * col);
}

int addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value) {
    int size;
    size = sizeArrayList(sm);
    insertArrayList(sm, size, (elementArrayList){row, col, value});
    return 1; 
}

int printSparseMatrix(sparseMatrix* sm) {
    printf("Sparse Matrix: \n");
    printArrayList(sm);
}

sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2) {
    sparseMatrix* smResult = createArrayList(100);
    int i, j;

    for (i = 0; i < sizeArrayList(sm1); i++) {  
        elementArrayList nonZeroOfSM1 = getItemArrayList(sm1, i);

        for (j = 0; j < sizeArrayList(sm2); j++) {  
            elementArrayList nonZeroOfSM2 = getItemArrayList(sm2, j);

            if (nonZeroOfSM1.col == nonZeroOfSM2.col &&
                nonZeroOfSM1.row == nonZeroOfSM2.row) {
                insertArrayList(smResult, sizeArrayList(smResult),
                    (elementArrayList){
                        nonZeroOfSM1.row,
                        nonZeroOfSM1.col,
                        nonZeroOfSM1.value + nonZeroOfSM2.value
                    });
                break;
            }
        }

        if (j == sizeArrayList(sm2)) {
            insertArrayList(smResult, sizeArrayList(smResult), nonZeroOfSM1);
        }
    }

    for (i = 0; i < sizeArrayList(sm2); i++) {
        elementArrayList nonZeroOfSM2 = getItemArrayList(sm2, i);
        int found = 0;
        int k;

        for (k = 0; k < sizeArrayList(sm1); k++) {
            elementArrayList nonZeroOfSM1 = getItemArrayList(sm1, k);
            if (nonZeroOfSM1.row == nonZeroOfSM2.row &&
                nonZeroOfSM1.col == nonZeroOfSM2.col) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            insertArrayList(smResult, sizeArrayList(smResult), nonZeroOfSM2);
        }
    }

    return smResult;
}