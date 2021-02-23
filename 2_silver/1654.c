#include <stdio.h>

/*
문제 : K개의 랜선을 일정한 크기로 잘라서 N개 이상을 만드려고 한다. 이때 N개 이상을 만들 수 있는 랜선의 최대 단위 길이를 구한다.

해결 방법 : 랜선의 길이 가운데 가장 긴 것을 기준으로 잡고 각각의 랜선을 나눈 몫들을 더한 것을 N과 비교하여 이분 탐색을 통해 길이를 찾는다.

주요 알고리즘 : 이분 탐색
*/

int lan[10240];

int main(void) {
     int k, n, b = 0;
     scanf("%d %d", &k, &n);
     for (int i = 0; i < k; i++) {
          scanf("%d", &lan[i]);
          if(lan[i] > b) b = lan[i];
     }

     long long int lo = 0, hi = (long long)b + 1, mid, ls;
     while (lo + 1 < hi) {
          mid = (lo + hi) / 2;
          ls = 0;
          for (int i = 0; i < k; i++) {
               ls += lan[i] / mid;
          }
          
          if (ls < n) {
               hi = mid;
          }
          else {
               lo = mid;
          }
     }
     printf("%lld", lo);
     return 0;
}