#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

// 재귀적 방법
long long fib_recursive(int n) {
    if (n == 1 || n == 2)
        return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// 반복(순환) 방법
long long fib_iterative(int n) {
    if (n == 1 || n == 2)
        return 1;

    long long a = 1, b = 1, result;

    for (int i = 3; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return b;
}

int main() {
    int N;

    printf("N 입력: ");
    scanf("%d", &N);

    printf("\nN\t재귀시간\t반복시간\n");

    for (int i = 1; i <= N; i++) {
        clock_t start, end;

        // 재귀 시간 측정
        start = clock();
        fib_recursive(i);
        end = clock();
        double time_recursive = (double)(end - start) / CLOCKS_PER_SEC;

        // 반복 시간 측정
        start = clock();
        fib_iterative(i);
        end = clock();
        double time_iterative = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%lf\t%lf\n", i, time_recursive, time_iterative);
    }

    return 0;
}