#include <stdio.h>

/*
문제 : N에서 시작해서 1초마다 2를 곱하거나 1을 더하거나 1을 빼는 연산이 가능하다고 할 때 K를 만드는데 걸리는 가장 빠른 시간을 구한다.(N, K <= 100000)

해결 방법 : BFS를 통해 맨 처음 큐에는 N을 넣고 이후로는 다음 큐에 2을 곱하거나 1을 더하거나 1을 뺀 숫자를 넣는다. K가 나오면 탐색을 종료한다.

주요 알고리즘 : 그래프 이론, BFS
*/

int f[131072], q[262144];
int qf = 0, qr = 0, qs = 0;

int main(void) {
     int n, k, t = -1;
     scanf("%d %d", &n, &k);
     q[0] = n;
     qr++;
     while (n != k) {
          qs = qr - qf;
          t++;
          while (qs) {
               n = q[qf];
               qf++;
               if (f[n] || n > 100000) {
                    qs--;
                    continue;
               }
               else {
                    f[n] = 1;
                    if (n == k) break;
                    if (n * 2 <= 100000 && !f[n * 2]) {
                         q[qr] = n * 2;
                         qr++;
                    }
                    if (n && !f[n - 1]) {
                         q[qr] = n - 1;
                         qr++;
                    }
                    if (!f[n + 1]) {
                         q[qr] = n + 1;
                         qr++;
                    }
                    qs--;
               }
          }
     }
     if (t < 0) t = 0;
     printf("%d", t);
     return 0;
}