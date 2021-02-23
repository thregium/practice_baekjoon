#include <stdio.h>

int small(int a, int b) {
     return a < b ? a : b;
}

int main(void) {
     int n, m, f = 0, t = 0;
     scanf("%d %d", &n, &m);
     for (int i = n / 5; i > 0; i /= 5) f += i;
     for (int i = m / 5; i > 0; i /= 5) f -= i;
     for (int i = (n - m) / 5; i > 0; i /= 5) f -= i;
     for (int i = n / 2; i > 0; i /= 2) t += i;
     for (int i = m / 2; i > 0; i /= 2) t -= i;
     for (int i = (n - m) / 2; i > 0; i /= 2) t -= i;
     printf("%d", small(f, t));
     return 0;
}