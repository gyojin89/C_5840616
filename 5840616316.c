#include <stdio.h>

int main() {
    union {
        float f;
        unsigned int u;
    } data;

    printf("실수를 입력하세요: ");
    scanf("%f", &data.f);

    printf("%u/", (data.u >> 31) & 1);

    for (int i = 30; i >= 23; i--) {
        printf("%u", (data.u >> i) & 1);
        if (i == 27) printf(" ");
    }

    printf("/");

    for (int i = 22; i >= 0; i--) {
        printf("%u", (data.u >> i) & 1);
        if (i % 4 == 3 && i != 3) printf(" ");
    }

    printf("\n");

    return 0;
}