#include <stdio.h>

long long int sq[32] = { 1, };

long long int mulsq(long long int a, long long int b, long long int c) {
     //printf("mulsq(%d, %d, %d)\n", a, b, c);
     if (b == 0) return a % c;
     else {
          long long int t = mulsq(a, b - 1, c);
          return t * t % c;
     }
}

long long int mulbig(long long int a, long long int b, long long int c) {
     if (b == 0) return 1;
     else if (b == 1) return a % c;
     for (int i = 31; i >= 0; i--) {
          if (b >= sq[i]) {
               return (mulsq(a, i, c) * mulbig(a, b - sq[i], c)) % c;
          }
     }
}

int main(void) {
     int a, b, c;
     scanf("%d %d %d", &a, &b, &c);
     for (int i = 1; i < 32; i++) sq[i] = sq[i - 1] * 2;
     printf("%lld", mulbig(a, b, c));
     return 0;
}