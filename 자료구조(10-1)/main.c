#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

void printMenu() {
    printf("\n==============================\n");
    printf("  양의 정수 순차 리스트 메뉴\n");
    printf("==============================\n");
    printf("1. 추가 (insert)\n");
    printf("2. 삭제 (delete)\n");
    printf("3. 변경 (replace)\n");
    printf("4. 출력 (print)\n");
    printf("5. 전체 삭제 (clear)\n");
    printf("0. 종료\n");
    printf("선택: ");
}

void printArrayListWithPos(arrayList* al) {
    if (isEmptyArrayList(al)) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    printf("\n위치\t값\n");
    printf("--------\n");
    for (int i = 0; i < al->size; i++) {
        printf("[%d]\t%d\n", i, al->data[i]);
    }
    printf("(size=%d, capacity=%d)\n", al->size, al->capacity);
}

int main() {
    arrayList* al = createArrayList(4);
    int choice, pos, value;

    printf("양의 정수 전용 순차 리스트 프로그램 시작\n");

    while (1) {
        printMenu();
        scanf("%d", &choice);

        if (choice == 0) {
            printf("프로그램을 종료합니다.\n");
            break;

        } else if (choice == 1) {
            printf("추가할 양의 정수 입력: ");
            scanf("%d", &value);
            if (value <= 0) {
                printf("오류: 양의 정수만 입력 가능합니다.\n");
                continue;
            }
            printf("추가할 위치 입력 (0 ~ %d): ", al->size);
            scanf("%d", &pos);
            if (insertArrayList(al, pos, value)) {
                printf("%d을(를) 위치 %d에 추가했습니다.\n", value, pos);
            } else {
                printf("오류: 잘못된 위치입니다.\n");
            }

        } else if (choice == 2) {
            if (isEmptyArrayList(al)) {
                printf("오류: 리스트가 비어 있습니다.\n");
                continue;
            }
            printf("삭제할 위치 입력 (0 ~ %d): ", al->size - 1);
            scanf("%d", &pos);
            int deleted = deleteArrayList(al, pos);
            if (deleted != 0 || pos == 0) {
                printf("위치 %d의 값 %d을(를) 삭제했습니다.\n", pos, deleted);
            } else {
                printf("오류: 잘못된 위치입니다.\n");
            }

        } else if (choice == 3) {
            if (isEmptyArrayList(al)) {
                printf("오류: 리스트가 비어 있습니다.\n");
                continue;
            }
            printf("변경할 위치 입력 (0 ~ %d): ", al->size - 1);
            scanf("%d", &pos);
            printf("새로운 양의 정수 입력: ");
            scanf("%d", &value);
            if (value <= 0) {
                printf("오류: 양의 정수만 입력 가능합니다.\n");
                continue;
            }
            if (replaceItemArrayList(al, pos, value)) {
                printf("위치 %d의 값을 %d로 변경했습니다.\n", pos, value);
            } else {
                printf("오류: 잘못된 위치입니다.\n");
            }

        } else if (choice == 4) {
            printArrayListWithPos(al);

        } else if (choice == 5) {
            initArrayList(al);
            printf("모든 항목을 삭제했습니다.\n");

        } else {
            printf("올바른 메뉴 번호를 입력하세요.\n");
        }
    }

    destroyArrayList(al);
    return 0;
}