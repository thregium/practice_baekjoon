#include <stdio.h>

int main(void) {
     int x, i, a, b, s = 0;
     scanf("%d", &x);
     for (i = 0; i < x; s++) i += s;
     a = i - x + 1;
     b = s - (i - x + 1);
     if (s % 2) printf("%d/%d", b, a);
     else printf("%d/%d", a, b);
     return 0;
}