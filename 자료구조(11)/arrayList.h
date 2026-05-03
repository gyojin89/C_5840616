#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int exponent;
    int coefficient;
} elementType;

typedef elementType elementArrayList;

typedef struct arrayListType {
    elementArrayList* data;
    int capacity;
    int size;
} arrayList;

extern arrayList* createArrayList(int size);
extern void destroyArrayList(arrayList* al);
extern int isEmptyArrayList(arrayList* al);
extern int isFullArrayList(arrayList* al);
extern int sizeArrayList(arrayList* al);
extern int insertArrayList(arrayList* al, int pos, elementArrayList item);
extern elementArrayList deleteArrayList(arrayList* al, int pos);
extern int initArrayList(arrayList* al);
extern elementArrayList getItemArrayList(arrayList* al, int pos);
extern int replaceItemArrayList(arrayList* al, int pos, elementArrayList item);
extern void printArrayList(arrayList* al);