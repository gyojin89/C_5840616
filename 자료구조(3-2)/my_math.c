#include "my_math.h"
#include <stdlib.h>   // abs()

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int g = gcd(a, b);
    // (|a| / g) * |b| 로 계산해 오버플로우 위험을 약간 완화
    return (abs(a) / g) * abs(b);
}