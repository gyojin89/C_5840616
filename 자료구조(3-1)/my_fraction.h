#ifndef MY_FRACTION_H
#define MY_FRACTION_H

typedef struct {
    int num;
    int den;
} Fraction;

Fraction reduce(Fraction f);
Fraction parse_fraction(char* str);
void print_fraction(Fraction f);
Fraction add(Fraction f1, Fraction f2);
Fraction subtract(Fraction f1, Fraction f2);
Fraction multiply(Fraction f1, Fraction f2);
Fraction divide(Fraction f1, Fraction f2);

#endif