#include "DCLinkedList.h"

static NodeType* getNodeAt(DCLinkedList* cl, int pos) {
    NodeType* cur = cl->tail->next;
    for (int i = 0; i < pos; i++)
        cur = cur->next;
    return cur;
}

DCLinkedList* createDCLinkedList() {
    DCLinkedList* cl = (DCLinkedList*)malloc(sizeof(DCLinkedList));
    cl->tail = NULL;
    cl->size = 0;
    return cl;
}

void destroyDCLinkedList(DCLinkedList* cl) {
    if (cl->size != 0) {
        NodeType* head = cl->tail->next;
        NodeType* cur  = head;
        for (int i = 0; i < cl->size; i++) {
            NodeType* nxt = cur->next;
            free(cur);
            cur = nxt;
        }
    }
    free(cl);
    printf("리스트가 메모리에서 해제되었습니다.\n");
}

int isEmptyDCLinkedList(DCLinkedList* cl) {
    return cl->size == 0;
}

int sizeDCLinkedList(DCLinkedList* cl) {
    return cl->size;
}

void insertFirstDCLinkedList(DCLinkedList* cl, int item) {
    NodeType* nPtr = (NodeType*)malloc(sizeof(NodeType));
    nPtr->data = item;

    if (cl->size == 0) {
       
        nPtr->next = nPtr;
        nPtr->prev = nPtr;
        cl->tail   = nPtr;
    } else {
        NodeType* head = cl->tail->next;
        
        nPtr->next    = head;
        nPtr->prev    = cl->tail;
        cl->tail->next = nPtr;
        head->prev    = nPtr;
    }
    cl->size++;
}

void insertLastDCLinkedList(DCLinkedList* cl, int item) {
    insertFirstDCLinkedList(cl, item); 
    cl->tail = cl->tail->next;        
}

void insertAtDCLinkedList(DCLinkedList* cl, int at, int item) {
    if (at < 0 || at > cl->size) {
        printf("오류: 유효하지 않은 위치입니다. (0 ~ %d)\n", cl->size);
        return;
    }
    if (at == 0) {
        insertFirstDCLinkedList(cl, item);
        return;
    }
    if (at == cl->size) {
        insertLastDCLinkedList(cl, item);
        return;
    }

    NodeType* pre  = getNodeAt(cl, at - 1);
    NodeType* post = pre->next;

    NodeType* nPtr = (NodeType*)malloc(sizeof(NodeType));
    nPtr->data = item;
    nPtr->next = post;
    nPtr->prev = pre;
    pre->next  = nPtr;
    post->prev = nPtr;
    cl->size++;
}

int deleteFirstDCLinkedList(DCLinkedList* cl) {
    if (isEmptyDCLinkedList(cl)) {
        printf("오류: 리스트가 비어 있습니다.\n");
        return -1;
    }
    NodeType* head = cl->tail->next;
    int data = head->data;

    if (cl->size == 1) {
        free(head);
        cl->tail = NULL;
    } else {
        NodeType* newHead = head->next;
        cl->tail->next   = newHead;
        newHead->prev    = cl->tail;
        free(head);
    }
    cl->size--;
    return data;
}

int deleteLastDCLinkedList(DCLinkedList* cl) {
    if (isEmptyDCLinkedList(cl)) {
        printf("오류: 리스트가 비어 있습니다.\n");
        return -1;
    }
    NodeType* tail = cl->tail;
    int data = tail->data;

    if (cl->size == 1) {
        free(tail);
        cl->tail = NULL;
    } else {
        NodeType* newTail   = tail->prev;
        NodeType* head      = tail->next;
        newTail->next = head;
        head->prev    = newTail;
        cl->tail      = newTail;
        free(tail);
    }
    cl->size--;
    return data;
}

int deleteAtDCLinkedList(DCLinkedList* cl, int at) {
    if (isEmptyDCLinkedList(cl)) {
        printf("오류: 리스트가 비어 있습니다.\n");
        return -1;
    }
    if (at < 0 || at >= cl->size) {
        printf("오류: 유효하지 않은 위치입니다. (0 ~ %d)\n", cl->size - 1);
        return -1;
    }
    if (at == 0)          return deleteFirstDCLinkedList(cl);
    if (at == cl->size-1) return deleteLastDCLinkedList(cl);

    NodeType* target = getNodeAt(cl, at);
    int data = target->data;

    target->prev->next = target->next;
    target->next->prev = target->prev;
    free(target);
    cl->size--;
    return data;
}

int getItemDCLinkedList(DCLinkedList* cl, int pos) {
    if (pos < 0 || pos >= cl->size) {
        printf("오류: 유효하지 않은 위치입니다.\n");
        return -1;
    }
    return getNodeAt(cl, pos)->data;
}

void replaceItemDCLinkedList(DCLinkedList* cl, int pos, int item) {
    if (pos < 0 || pos >= cl->size) {
        printf("오류: 유효하지 않은 위치입니다.\n");
        return;
    }
    getNodeAt(cl, pos)->data = item;
}

void printDCLinkedList(DCLinkedList* cl) {
    printf("\n[전체 목록] 크기: %d\n", cl->size);
    if (cl->size == 0) {
        printf("(리스트가 비어 있습니다)\n\n");
        return;
    }
    printf("HEAD <->");
    NodeType* cur = cl->tail->next;
    for (int i = 0; i < cl->size; i++) {
        printf("[%d]%d", i, cur->data);
        if (i < cl->size - 1) printf("<->");
        cur = cur->next;
    }
    printf("<-> TAIL(원형)\n\n");
}