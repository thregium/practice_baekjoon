#include <stdio.h>

/*
문제 : N 이하의 두 자연수를 곱한 모든 조합이 있으면 오름차순으로 K번째 수는 몇인지 구한다. N과 K만 주어진다.

해결 방법 : 숫자 m보다 작은 조합의 갯수는 O(N)의 시간 내 구할 수 있으므로 숫자 m보다 작은 조합의 수를 비교해가며 이분 탐색을 사용하여 K번째 수를 구한다.

주요 알고리즘 : 이분 탐색
*/

long long int small(long long a, long long b) {
     return a < b ? a : b;
}

int main(void) {
     int n, k;
     scanf("%d%d", &n, &k);

     long long int l = 0, h = (long long)n * n, m, c;
     while (l + 1 < h) {
          m = (l + h) / 2;
          c = 0;
          for (int i = 1; i <= n; i++) {
               c += small(n, m / i);
          }

          if (c < k) {
               l = m;
          }
          else {
               h = m;
          }
     }
     printf("%d", h);
     return 0;
}