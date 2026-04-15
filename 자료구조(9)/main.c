#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

int main() {
    arrayList* = myArrayList;
    myArrayList = createArrayList(100);

    if (sizeArrayList(myArrayList) == 0) {
        printf("Craete ok\n");
    }

    insertArrayList(myArrayList, 0, 10);
    insertArrayList(myArrayList, 1, 20);
    insertArrayList(myArrayList, 2, 30);
    insertArrayList(myArrayList, 0, 5);

    printfarrayList(myArrayList);

    deleteArrayList(myArrayList, 0);
    deleteArrayList(myArrayList, 1);
    deleteArrayList(myArrayList, 2);

    deleteArrayList(myArrayList);
}