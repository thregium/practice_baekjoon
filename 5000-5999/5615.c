#include <stdio.h>
#define ULL unsigned long long
#define MAXI 2147483647

/*
문제 : 주어진 수열 가운데 방정식 A = 2xy + x + y의 양의 정수로 이루어진 해가 없는 A의 수를 구한다.

해결 방법 : 2xy + x + y는 2를 곱하면 4xy + 2x + 2y가 되고, (2x + 1)(2y + 1) = 4xy + 2x + 2y가 되므로 이 문제는 A * 2 + 1이 3 이상의 두 홀수로 이루어졌는지를
묻는 것과 같다. 그런데 3 이상의 두 홀수를 곱해 만들 수 없는 홀수는 3 이상의 소인수가 없다는 의미이고, 홀수이므로 2도 소인수로 갖지 않는다.
그러므로 주어진 방정식의 해를 구할 수 없는 수에 2를 곱하고 1을 더한 수는 소수이다.

소수 판정을 해야 하는 수가 최대 2^32 - 1이므로 일반적인 소수 판정법으로는 해를 구할 수 없고, 밀러-라빈 판정법을 이용해 구한다.
밀러 라빈 판정시 판정할 값이 2^32 이하인 경우에는 a값이 2, 7, 61인 경우 결정론적임이 증명되었으므로 이 3가지 경우만 판단하면 된다.
이때 제곱시에는 분할 정복을 사용하고, 2^n인 경우는 메모이제이션을 통해 시간을 절약해야 한다. 또한, 오버 플로우에 주의한다.

주요 알고리즘 : 수학, 정수론, 밀러-라빈
*/

int cal = 0;
ULL mem[32];

ULL sqrmul(ULL a, ULL b, ULL c) {
     if (c == 1) return (a * a) % b;
     ULL r = sqrmul(a, b, c - 1);
     //cal++;
     return mem[c] = (r * r) % b;
}

ULL powbig(ULL a, ULL b, ULL c) {
     if (c == 0) return 1;
     if (c == 1) return a % b;
     for (int i = 31; i > 0; i--) {
          //cal++;
          if (c >= 1LL << i) {
               return ((mem[i] ? mem[i] : sqrmul(a, b, i)) * powbig(a, b, c - (1LL << i)) % b);
          }
     }
}

int isprime(ULL n) {
     int a[] = { 2, 7, 61 };
     int s = 0, r = 0;
     ULL d = n - 1, t;
     for (ULL x = n - 1; x % 2 == 0; x /= 2) {
          s++;
          d = x / 2;
     }
     for (int i = 0; i < 3; i++) {
          if (a[i] >= n) break;
          //cal++;
          r = 0;
          for (int i = 0; i < 32; i++) mem[i] = 0;
          t = powbig(a[i], n, d);
          if (t == 1 || t == n - 1) {
               r = 1;
               continue;
          }
          for (int j = 0; j < s; j++) {
               //cal++;
               t = t * t % n;
               if (t == n - 1) {
                    r = 1;
                    continue;
               }
          }
          if (r == 0) {
               return 0;
          }
     }
     return 1;
}

int main(void) {
     int n, no = 0;
     ULL apt;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%lld", &apt);
          //apt = i + 1LL;
          //apt = i + 2100000000LL;
          //apt = (ULL)MAXI - i;
          if (isprime(apt * 2 + 1)) {
               //printf("%lld is prime\n", (ULL)apt * 2 + 1);
               no++;
               //if (cal > 150000000) return 1;
          }
     }
     printf("%d", no);
     return 0;
}