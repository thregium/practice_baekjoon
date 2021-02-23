#include <stdio.h>

/*
문제 : N그루의 나무의 일정 높이 이상을 잘라 M미터의 목재를 수집하려고 한다. 나무의 높이가 주어질 때 M미터 이상의 목재를 얻을 수 있는 최대 높이를 구한다.

해결 방법 : 나무의 높이 가운데 가장 긴 것을 기준으로 잡고 설정된 높이보다 높은 각각의 나무 높이를 설정된 높이에서 뺀 것을 더한 것을 M과 비교하여 이분 탐색을 통해 높이를 찾는다.

주요 알고리즘 : 이분 탐색
*/

int forest[1048576];

int main(void) {
     int n, m, b = 0;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < n; i++) {
          scanf("%d", &forest[i]);
          if (forest[i] > b) b = forest[i];
     }

     int lo = 0, hi = b + 1, mid;
     long long int wood;
     while (lo + 1 < hi) {
          mid = (lo + hi) / 2;
          wood = 0;
          for (int i = 0; i < n; i++) {
               wood += (forest[i] - mid > 0 ? forest[i] - mid : 0);
          }

          if (wood < m) {
               hi = mid;
          }
          else {
               lo = mid;
          }
     }
     printf("%d", lo);
     return 0;
}