#include <stdio.h>

/*
문제 : 6이 3개 연속으로 들어가는 N(N <= 10000)번째 수를 구한다.

해결 방법 : 무한루프를 돌리며 1부터 순서대로 6이 3개 연속하는지 여부를 확인한 후
N번째 수까지 찾더라도 시간 내에 찾을 수 있다.

주요 알고리즘 : 브루트 포스
*/

int main(void) {
     int n, t, i, j, x = 0;
     int d[20];
     scanf("%d", &n);
     for (i = 0; x < n; i++) {
          t = i;
          for (j = 0; t > 0; j++) {
               d[j] = t % 10;
               t /= 10;
          }
          for (int k = 0; k < j - 2; k++) {
               if (d[k] == 6 && d[k + 1] == 6 && d[k + 2] == 6) {
                    //printf("%d\n", i);
                    x++;
                    break;
               }
          }
     }
     printf("%d", i - 1);
     return 0;
}