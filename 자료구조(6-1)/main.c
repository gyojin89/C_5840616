#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;
    int *arr;
    int i;

    int sum = 0;
    int max, min;

    printf("정수 N을 입력하세요: ");
    scanf("%d", &N);

    arr = (int *)malloc(sizeof(int) * N);
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        *(arr + i) = rand() % (N + 1);
    }

    printf("\n[정방향 출력]\n");
    for (i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }

    printf("\n\n[역방향 출력]\n");
    for (i = N - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }

    max = *arr;
    min = *arr;

    for (i = 0; i < N; i++) {
        int value = *(arr + i);

        sum += value;

        if (value > max) {
            max = value;
        }

        if (value < min) {
            min = value;
        }
    }

    printf("\n\n[결과]\n");
    printf("총합: %d\n", sum);
    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    free(arr);

    return 0;
}