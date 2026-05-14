#include "LinkedList.h"

void printMenu() {
    printf("\n연결 리스트 메뉴\n");
    printf("1. 맨 앞에 추가\n");
    printf("2. 맨 뒤에 추가\n");
    printf("3. 특정 위치에 추가\n");
    printf("4. 특정 위치 삭제\n");
    printf("5. 전체 목록 출력\n");
    printf("6. 리스트 크기 확인\n");
    printf("0. 종료\n");
    printf("\n");
    printf("선택: ");
}

int main() {
    LinkedList* ls = createLinkedList();
    int choice, value, index;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("추가할 정수 입력: ");
                scanf("%d", &value);
                insertFirstLinkedList(ls, value);
                printf("정수 %d, 리스트의 가장 앞에 삽입.\n", value);
                break;

            case 2:
                printf("추가할 정수 입력: ");
                scanf("%d", &value);
                insertLastLinkedList(ls, value);
                printf("정수 %d, 리스트의 가장 뒤에 삽입.\n", value);
                break;

            case 3:
                printf("삽입할 위치(0-based index) 입력: ");
                scanf("%d", &index);
                printf("추가할 정수 입력: ");
                scanf("%d", &value);
                insertAtLinkedList(ls, index, value);
                printf("%d번 위치에 정수 %d, 삽입\n", index, value);
                break;

            case 4:
                printf("삭제할 위치(0-based index) 입력: ");
                scanf("%d", &index);
                value = deleteAtLinkedList(ls, index);
                if (value != -1)
                    printf("%d번 위치의 값 정수: %d, 삭제\n", index, value);
                break;

            case 5:
                printLinkedList(ls);
                break;

            case 6:
                printf("현재 리스트 크기: %d\n", sizeLinkedList(ls));
                break;

            case 0:
                destroyLinkedList(ls);
                printf("메모리 해제 및 프로그램 종료.\n");
                return 0;

            default:
                printf("잘못된 입력입니다. 다시 선택하세요.\n");
                break;
        }
    }
}
