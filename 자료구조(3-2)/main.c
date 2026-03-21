#include <stdio.h>
#include "my_math.h"

int main(void) {
    int x, y;

    /* 두 정수를 표준 입력으로 읽는다. */
    if (scanf("%d %d", &x, &y) != 2) {
        fprintf(stderr, "입력 오류: 두 정수를 입력하세요.\n");
        return 1;
    }

    int g = gcd(x, y);
    int l = lcm(x, y);

    printf("GCD: %d, LCM: %d\n", g, l);
    return 0;
}