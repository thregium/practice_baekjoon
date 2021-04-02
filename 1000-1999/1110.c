#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
     int n, t, s = 0;
     scanf("%d", &n);
     t = n;
     while ((n != t) || (!s)) {
          t = (t % 10) * 10 + (t / 10 + t % 10) % 10;
          s++;
     }
     printf("%d", s);
     return 0;
}