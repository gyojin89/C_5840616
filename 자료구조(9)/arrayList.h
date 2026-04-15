#include <stdio.h>
#include <stdlib.h>

typedef int elementArrayList; 

typedef struct arrayListType {
    elementArrayList* data; 
    int capacity;
} arraylist;

extern ArrayList* craeteArrayList (int size);
extern void destroArrayList (arrayList* al);
extern int isemptyArrayList (arrayList* al);
extern int isfullArrayList (arrayList* al);
extern int sizeArrayList (arrayList* al);
extern int insertArrayList (arrayList* al,
    int pos, elementArrayList item);
extern elementArrayList deleteArrayList(
    arrayList* al, int pos);
extern int initArrayList (arrayList, al);
extern elementArrayList getItemArrayList(
    arrayList* al, int pos);
extern int replaceItemArrayList(arrayList* al,
    int pos, elementArrayList item);
extern void printArrayList(arrayList* al);