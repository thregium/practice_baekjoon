#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
     int a, b;
     double f;
     scanf("%d %d", &a, &b);
     f = (double)a / b;
     printf("%lf", f);
     return 0;
}
