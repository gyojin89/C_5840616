#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ItemType;

typedef struct Node {
    ItemType data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

LinkedList* createLinkedList();
void destroyLinkedList(LinkedList* ls);

int isEmptyLinkedList(LinkedList* ls);
int sizeLinkedList(LinkedList* ls);

void insertFirstLinkedList(LinkedList* ls, ItemType item);
void insertLastLinkedList(LinkedList* ls, ItemType item);
void insertItemLinkedList(LinkedList* ls, Node* pre, ItemType item);
void insertAtLinkedList(LinkedList* ls, int at, ItemType item);
ItemType deleteFirstLinkedList(LinkedList* ls);
ItemType deleteLastLinkedList(LinkedList* ls);
ItemType deleteItemLinkedList(LinkedList* ls, Node* pos);
ItemType deleteAtLinkedList(LinkedList* ls, int at);

ItemType getItemLinkedList(LinkedList* ls, int pos);
void replaceItemLinkedList(LinkedList* ls, int pos, ItemType item);
ItemType nextItemLinkedList(LinkedList* ls, Node* pre);

void printLinkedList(LinkedList* ls);

#endif
