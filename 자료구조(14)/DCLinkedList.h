#ifndef DCLINKEDLIST_H
#define DCLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* prev;
    struct NodeType* next;
} NodeType;

typedef struct {
    NodeType* tail;
    int size;
} DCLinkedList;

DCLinkedList* createDCLinkedList();
void          destroyDCLinkedList(DCLinkedList* cl);

int  isEmptyDCLinkedList(DCLinkedList* cl);
int  sizeDCLinkedList(DCLinkedList* cl);

void insertFirstDCLinkedList(DCLinkedList* cl, int item);
void insertLastDCLinkedList(DCLinkedList* cl, int item);
void insertAtDCLinkedList(DCLinkedList* cl, int at, int item);

int  deleteFirstDCLinkedList(DCLinkedList* cl);
int  deleteLastDCLinkedList(DCLinkedList* cl);
int  deleteAtDCLinkedList(DCLinkedList* cl, int at);

int  getItemDCLinkedList(DCLinkedList* cl, int pos);
void replaceItemDCLinkedList(DCLinkedList* cl, int pos, int item);

void printDCLinkedList(DCLinkedList* cl);

#endif