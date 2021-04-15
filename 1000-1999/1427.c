#include <stdio.h>

/*
문제 : 수가 주어지면 이 수의 각 자릿수를 내림차순으로 정렬한다.

해결 방법 : 수의 각 자릿수를 저장받은 후, 정렬한다.

주요 알고리즘 : 구현, 정렬
*/

int main(void) {
     int n, m, x = 0;
     int d[16], e[16];
     scanf("%d", &n);
     while (n > 0) {
          d[x] = n % 10;
          n /= 10;
          x++;
     }
     for (int i = 0; i < x; i++) {
          m = 0;
          for (int j = 0; j < x; j++) {
               if (d[j] > d[m]) m = j;
          }
          e[i] = d[m];
          d[m] = -1;
     }
     for (int i = 0; i < x; i++) printf("%d", e[i]);
     return 0;
}