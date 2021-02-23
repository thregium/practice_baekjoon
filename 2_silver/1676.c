#include <stdio.h>

int main(void) {
     int n, f = 0;
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) {
           if (i % 5 == 0) {
                for (int t = i; t % 5 == 0; t /= 5) f++;
           }
     }
     printf("%d", f);
     return 0;
}