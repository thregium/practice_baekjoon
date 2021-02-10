#include <stdio.h>

/*
문제 : N개의 라면 공장에서 정확히 A[i]개의 라면을 사야 한다. 라면을 사는 방법은 7원을 주고 i, i + 1, i + 2번 공장에서 라면을 하나씩 사거나
5원을 주고 i, i + 1번 공장에서 하나씩 사거나 3원을 주고 i번 공장에서 라면을 하나 사는 방법이 있다. 이 방법을 통해 라면을 살 때 드는 최소 비용을 출력한다.

해결 방법 : 한번에 최대한 많은 라면을 사는 것이 대부분의 상황에서 유리하다. 단, i + 1번 공장에서 살 라면이 i번과 i + 2번 공장에서 살 라면보다 많은 경우에는
먼저 2곳에서 사고 다음에 3곳에서 사는 것이 더 싼 값에 살 수 있다. 그러므로 그리디 알고리즘을 사용해서 현 위치에서 가장 많이 살 수 있는 방법을 선택하되
i + 1번 공장에서 필요한 수가 i번과 i + 2번에서 필요한 수보다 많은 경우 2개 + 3개를 살 수 있도록 예외를 두어야 한다.

주요 알고리즘 : 그리디 알고리즘
*/

int a[10240];
int arr[10] = { 1, 5, 25, 125, 625 };
int t = 0;

long long int small(long long int a, long long int b) {
     return a < b ? a : b;
}

int small3(int a, int b, int c) {
     return small(small(a, b), c);
}

long long int bf(int n, long long x, long long rr) {
     for (int i = 0; i < n; i++) {
          if (i < n - 2 && a[i] && a[i + 1] && a[i + 2]) {
               a[i]--;
               a[i + 1]--;
               a[i + 2]--;
               rr = small(rr, bf(n, x + 7, rr));
               a[i]++;
               a[i + 1]++;
               a[i + 2]++;
          }
          if (i < n - 1 && a[i] && a[i + 1]) {
               a[i]--;
               a[i + 1]--;
               rr = small(rr, bf(n, x + 5, rr));
               a[i]++;
               a[i + 1]++;
          }
          if (a[i]) {
               a[i]--;
               rr = small(rr, bf(n, x + 3, rr));
               a[i]++;
          }
     }
     for (int i = 0; i < n; i++) {
          if (a[i]) return rr;
     }
     if (x < rr) {
          rr = x;
          x = 0;
          return rr;
     }
     else {
          x = 0;
          return rr;
     }
}

int main(void) {
     int n, s, f = 0;
     long long int rr = 0, r = 0;
     long long int sum = 0;
     while (t < 625) {
          //scanf("%d", &n);
          n = 4;
          for (int i = 0; i < n; i++) {
               //scanf("%d", &a[i]);
               a[i] = (t / arr[i]) % 5;
               sum += a[i];
          }
          //printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);

          //brute-force

          rr = bf(n, 0, 999999999999);
          r = 0;


          for (int i = 0; i < n; i++) {
               if (i < n - 2 && a[i] && a[i + 1] && a[i + 2]) {
                    if (f) {
                         s = small(a[i], a[i + 1]);
                         a[i] -= s;
                         a[i + 1] -= s;
                         r += s * 5;
                         f = 0;
                         //printf("(i = %d) #+5 * %d\n", i, s);
                    }
                    else {
                         s = small3(a[i], a[i + 1], a[i + 2]);
                         if (a[i] < a[i + 1] && a[i + 1] > a[i + 2]) {
                              f = 1;
                              s -= small(small(a[i], a[i + 2]), small(a[i + 1] - a[i], a[i + 1] - a[i + 2]));
                         }
                         a[i] -= s;
                         a[i + 1] -= s;
                         a[i + 2] -= s;
                         r += s * 7;
                         //printf("(i = %d) +7 * %d\n", i, s);
                         i--;
                         continue;
                    }
               }
               if (i < n - 1 && a[i] && a[i + 1]) {
                    s = small(a[i], a[i + 1]);
                    a[i] -= s;
                    a[i + 1] -= s;
                    r += s * 5;
                    //printf("(i = %d) +5 * %d\n", i, s);
               }
               if (a[i]) {
                    s = a[i];
                    a[i] -= s;
                    r += s * 3;
                    //printf("(i = %d) +3 * %d\n", i, s);
               }
          }

          //printf("rr = %lld, r = %lld\n\n", rr, r);
          if (rr != r) {
               for (int i = 0; i < n; i++) {
                    a[i] = (t / arr[i]) % 5;
                    printf("%d ", a[i]);
               }
               printf("\nrr = %lld, r = %lld\n", rr, r);
               printf("!!!!RR != R!!!!\n");
          }

          t++;
     }
     return 0;
}