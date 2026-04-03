#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int **arr;
    int i, j;

    printf("홀수 N을 입력하세요: ");
    scanf("%d", &N);

    if (N % 2 == 0) {
        printf("홀수만 입력 가능합니다.\n");
        return 1;
    }

    arr = (int **)malloc(sizeof(int *) * N);
    for (i = 0; i < N; i++) {
        *(arr + i) = (int *)malloc(sizeof(int) * N);
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            *(*(arr + i) + j) = 0;
        }
    }

    int num = 1;
    int row = 0;
    int col = N / 2;

    while (num <= N * N) {
        *(*(arr + row) + col) = num;

        int next_row = (row - 1 + N) % N;
        int next_col = (col + 1) % N;

        if (*(*(arr + next_row) + next_col) != 0) {
            row = (row + 1) % N;
        } else {
            row = next_row;
            col = next_col;
        }

        num++;
    }

    printf("\n[마방진]\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%4d", *(*(arr + i) + j));
        }
        printf("\n");
    }

    printf("\n[합 검증]\n");

    int sum;

    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
            sum += *(*(arr + i) + j);
        }
        printf("가로 %d번째 합: %d\n", i + 1, sum);
    }

    for (j = 0; j < N; j++) {
        sum = 0;
        for (i = 0; i < N; i++) {
            sum += *(*(arr + i) + j);
        }
        printf("세로 %d번째 합: %d\n", j + 1, sum);
    }

    sum = 0;
    for (i = 0; i < N; i++) {
        sum += *(*(arr + i) + i);
    }
    printf("대각선(↘) 합: %d\n", sum);

    sum = 0;
    for (i = 0; i < N; i++) {
        sum += *(*(arr + i) + (N - 1 - i));
    }
    printf("대각선(↙) 합: %d\n", sum);

    for (i = 0; i < N; i++) {
        free(*(arr + i));
    }
    free(arr);

    return 0;
}