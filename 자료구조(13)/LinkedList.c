#include "LinkedList.h"

LinkedList* createLinkedList() {
    LinkedList* ls = (LinkedList*)malloc(sizeof(LinkedList));
    ls->head = NULL;
    ls->size = 0;
    return ls;
}

void destroyLinkedList(LinkedList* ls) {
    Node* cur = ls->head;
    while (cur != NULL) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    free(ls);
}

int isEmptyLinkedList(LinkedList* ls) {
    return ls->size == 0;
}

int sizeLinkedList(LinkedList* ls) {
    return ls->size;
}

void insertFirstLinkedList(LinkedList* ls, ItemType item) {
    Node* nPtr = (Node*)malloc(sizeof(Node));
    nPtr->data = item;
    nPtr->next = ls->head;
    ls->head = nPtr;
    ls->size++;
}

void insertLastLinkedList(LinkedList* ls, ItemType item) {
    Node* nPtr = (Node*)malloc(sizeof(Node));
    nPtr->data = item;
    nPtr->next = NULL;

    if (isEmptyLinkedList(ls)) {
        ls->head = nPtr;
    } else {
        Node* cur = ls->head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = nPtr;
    }
    ls->size++;
}
void insertItemLinkedList(LinkedList* ls, Node* pre, ItemType item) {
    if (pre == NULL) {
        insertFirstLinkedList(ls, item);
        return;
    }
    Node* nPtr = (Node*)malloc(sizeof(Node));
    nPtr->data = item;
    nPtr->next = pre->next;
    pre->next = nPtr;
    ls->size++;
}

void insertAtLinkedList(LinkedList* ls, int at, ItemType item) {
    if (at < 0 || at > ls->size) {
        printf("오류: 유효하지 않은 인덱스 %d (크기: %d)\n", at, ls->size);
        return;
    }
    if (at == 0) {
        insertFirstLinkedList(ls, item);
        return;
    }
    Node* cur = ls->head;
    for (int i = 0; i < at - 1; i++)
        cur = cur->next;
    insertItemLinkedList(ls, cur, item);
}

ItemType deleteFirstLinkedList(LinkedList* ls) {
    if (isEmptyLinkedList(ls)) {
        printf("오류: 리스트가 비었음.\n");
        return -1;
    }
    Node* target = ls->head;
    ItemType data = target->data;
    ls->head = target->next;
    free(target);
    ls->size--;
    return data;
}

ItemType deleteLastLinkedList(LinkedList* ls) {
    if (isEmptyLinkedList(ls)) {
        printf("오류: 리스트가 비었음.\n");
        return -1;
    }
    ItemType data;
    if (ls->size == 1) {
        data = ls->head->data;
        free(ls->head);
        ls->head = NULL;
    } else {
        Node* cur = ls->head;
        while (cur->next->next != NULL)
            cur = cur->next;
        data = cur->next->data;
        free(cur->next);
        cur->next = NULL;
    }
    ls->size--;
    return data;
}

ItemType deleteItemLinkedList(LinkedList* ls, Node* pos) {
    if (isEmptyLinkedList(ls) || pos == NULL) {
        printf("오류: 삭제할 노드가 없음.\n");
        return -1;
    }
    ItemType data = pos->data;
    if (pos == ls->head) {
        ls->head = pos->next;
        free(pos);
    } else {
        Node* cur = ls->head;
        while (cur->next != pos)
            cur = cur->next;
        cur->next = pos->next;
        free(pos);
    }
    ls->size--;
    return data;
}

ItemType deleteAtLinkedList(LinkedList* ls, int at) {
    if (at < 0 || at >= ls->size) {
        printf("오류: 유효하지 않은 인덱스 %d (크기: %d)\n", at, ls->size);
        return -1;
    }
    Node* cur = ls->head;
    for (int i = 0; i < at; i++)
        cur = cur->next;
    return deleteItemLinkedList(ls, cur);
}


ItemType getItemLinkedList(LinkedList* ls, int pos) {
    if (pos < 0 || pos >= ls->size) {
        printf("오류: 유효하지 않은 인덱스 %d\n", pos);
        return -1;
    }
    Node* cur = ls->head;
    for (int i = 0; i < pos; i++)
        cur = cur->next;
    return cur->data;
}

void replaceItemLinkedList(LinkedList* ls, int pos, ItemType item) {
    if (pos < 0 || pos >= ls->size) {
        printf("오류: 유효하지 않은 인덱스 %d\n", pos);
        return;
    }
    Node* cur = ls->head;
    for (int i = 0; i < pos; i++)
        cur = cur->next;
    cur->data = item;
}

ItemType nextItemLinkedList(LinkedList* ls, Node* pre) {
    if (pre == NULL || pre->next == NULL) {
        printf("오류: 다음 노드 없음.\n");
        return -1;
    }
    return pre->next->data;
}

void printLinkedList(LinkedList* ls) {
    printf("Print LinkedList:\n");
    printf("Size: %d\n", ls->size);
    if (isEmptyLinkedList(ls)) {
        printf("(empty)\n");
        return;
    }
    Node* cur = ls->head;
    int i = 0;
    while (cur != NULL) {
        printf("[%d] %d\n", i++, cur->data);
        cur = cur->next;
    }
}
