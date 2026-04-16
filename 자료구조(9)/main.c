#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

int main() {
   arrayList* al = craeteArrayList(5);

   insertElementSparseMatrix(2, 1, 10);
   insertElementSparseMatrix(3, 3, 15);
   insertElementSparseMatrix(4, 1, 3);

   printArrayList(al);

  destroArrayList(al);

  return 0;
}