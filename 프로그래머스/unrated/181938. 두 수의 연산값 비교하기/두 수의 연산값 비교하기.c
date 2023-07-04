#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int a, int b) {
    int blen = log10(b);
    int ab = a*pow(10,blen+1) + b;
    int ab2 = 2*a*b;
    return ab > ab2 ? ab : ab2;
}