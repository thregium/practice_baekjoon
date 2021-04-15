#include <stdio.h>

/*
문제 : N(N <= 100000) 길이의 순열이 주어질 때, 1, 2, 3 ... N 으로 이루어진 순열과 이어서
교차하는 선이 없도록 하기 위해 제거해야 하는 최소한의 정점의 수를 구한다.

해결 방법 : LIS를 구한다. 단, NlogN 시간 내에 구해야 한다. 구한 LIS의 값을 정점의 수에서 뺀 후 출력한다.

주요 알고리즘 : 이분 탐색, LIS
*/

int a[2097152];
int p[2097152];
int x = 1;

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &a[i]);
     }
     p[0] = a[0];
     x = 1;

     int l, h, m, k;
     for (int i = 1; i < n; i++) {
          k = a[i];
          l = 0;
          h = x - 1;
          if (k > p[x - 1]) {
               p[x] = k;
               x++;
               continue;
          }

          while (l < h) {
               m = (l + h) / 2;

               if (p[m] > k) {
                    h = m - 1;
               }
               else if (p[m] == k) break;
               else {
                    l = m + 1;
               }
          }

          if (p[l] == k) continue;
          else {
               while (k > p[l]) l++;
               p[l] = k;
          }
     }
     printf("%d", n - x);
     return 0;
}