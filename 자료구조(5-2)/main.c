#include <stdio.h>

#define N 3

int main() {
    int magic[N][N] = {0};

    int num = 1;
    int row = 0;
    int col = N / 2;

    while (num <= N * N) {
        magic[row][col] = num;

        int next_row = (row - 1 + N) % N;
        int next_col = (col + 1) % N;

        if (magic[next_row][next_col] != 0) {
            row = (row + 1) % N;
        } else {
            row = next_row;
            col = next_col;
        }

        num++;
    }

    printf("마방진 (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", magic[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += magic[i][j];
        }
        printf("가로 %d 합: %d\n", i + 1, sum);
    }

    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += magic[i][j];
        }
        printf("세로 %d 합: %d\n", j + 1, sum);
    }

    int diag1 = 0, diag2 = 0;

    for (int i = 0; i < N; i++) {
        diag1 += magic[i][i];
        diag2 += magic[i][N - i - 1];
    }

    printf("첫번째 대각선 합: %d\n", diag1);
    printf("두번째 대각선 합: %d\n", diag2);

    return 0;
}