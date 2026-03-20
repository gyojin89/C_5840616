 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_fraction.h"
#include "my_math.h"

Fraction reduce(Fraction f) {
    int common = gcd(f.num, f.den);
    f.num /= common;
    f.den /= common;
    if (f.den < 0) { f.num = -f.num; f.den = -f.den; }
    return f;
}

Fraction parse_fraction(char* str) {
    Fraction f;
    sscanf(str, "%d/%d", &f.num, &f.den);
    return reduce(f);
}

void print_fraction(Fraction f) {
    printf("%d/%d", f.num, f.den);
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction res = {f1.num * f2.den + f2.num * f1.den, f1.den * f2.den};
    return reduce(res);
}

Fraction subtract(Fraction f1, Fraction f2) {
    Fraction res = {f1.num * f2.den - f2.num * f1.den, f1.den * f2.den};
    return reduce(res);
}

Fraction multiply(Fraction f1, Fraction f2) {
    Fraction res = {f1.num * f2.num, f1.den * f2.den};
    return reduce(res);
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction res = {f1.num * f2.den, f1.den * f2.num};
    return reduce(res);
}