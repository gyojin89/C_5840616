#include <stdio.h>
#include <string.h>
#include "my_fraction.h"

int main() {
    char s1[20], op[5], s2[20];
    scanf("%s %s %s", s1, op, s2);

    Fraction f1 = parse_fraction(s1);
    Fraction f2 = parse_fraction(s2);
    Fraction result;

    if (strcmp(op, "+") == 0) result = add(f1, f2);
    else if (strcmp(op, "-") == 0) result = subtract(f1, f2);
    else if (strcmp(op, "*") == 0) result = multiply(f1, f2);
    else if (strcmp(op, "/") == 0) result = divide(f1, f2);

    print_fraction(result);
    printf("\n");

    return 0;
}