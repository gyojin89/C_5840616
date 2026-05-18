#include "DCLinkedList.h"

void printMenu() {
    printf("이중 원형 연결 리스트 메뉴\n");
    printf("1. 맨 앞에 추가\n");
    printf("2. 맨 뒤에 추가\n");
    printf("3. 특정 위치에 추가\n");
    printf("4. 특정 위치 삭제\n");
    printf("5. 전체 목록 출력\n");
    printf("6. 리스트 크기 확인\n");
    printf("0. 종료\n");
    printf("선택: ");
}

int main(void) {
    DCLinkedList* cl = createDCLinkedList();
    int choice, item, at, result;

    printf("이중 원형 연결 리스트 프로그램을 시작합니다.\n\n");

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("추가할 정수 입력: ");
            scanf("%d", &item);
            insertFirstDCLinkedList(cl, item);
            printf("%d을(를) 맨 앞에 추가했습니다.\n\n", item);
            break;

        case 2:
            printf("추가할 정수 입력: ");
            scanf("%d", &item);
            insertLastDCLinkedList(cl, item);
            printf("%d을(를) 맨 뒤에 추가했습니다.\n\n", item);
            break;

        case 3:
            printf("삽입할 위치(0 ~ %d) 입력: ", cl->size);
            scanf("%d", &at);
            printf("추가할 정수 입력: ");
            scanf("%d", &item);
            insertAtDCLinkedList(cl, at, item);
            printf("위치 %d에 %d을(를) 추가했습니다.\n\n", at, item);
            break;

        case 4:
            if (isEmptyDCLinkedList(cl)) {
                printf("오류: 리스트가 비어 있습니다.\n\n");
                break;
            }
            printf("삭제할 위치(0 ~ %d) 입력: ", cl->size - 1);
            scanf("%d", &at);
            result = deleteAtDCLinkedList(cl, at);
            if (result != -1)
                printf("위치 %d의 값 %d을(를) 삭제했습니다.\n\n", at, result);
            break;

        case 5:
            printDCLinkedList(cl);
            break;

        case 6:
            printf("현재 리스트 크기: %d\n\n", sizeDCLinkedList(cl));
            break;

        case 0:
            destroyDCLinkedList(cl);
            printf("프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("잘못된 입력입니다. 다시 선택해주세요.\n\n");
            break;
        }
    }
}