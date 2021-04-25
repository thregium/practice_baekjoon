#include <stdio.h>

/*
문제 : 5자리 이하의 수가 주어질 때 이 수가 팰린드롬수인지 검사한다.

해결 방법 : 자릿수에 따라 경우를 나누어 구한다.

주요 알고리즘 : 수학, 구현?

출처 : NZPC 2006 B번
*/

int main(void) {
     int n, p;
     while (1) {
          scanf("%d", &n);
          if (!n) break;
          p = 1;
          
          if (n > 9999) {
               if ((n / 10000 != n % 10) || ((n / 1000) % 10 != (n / 10) % 10)) p = 0;
          }
          else if (n > 999) {
               if ((n / 1000 != n % 10) || ((n / 100) % 10 != (n / 10) % 10)) p = 0;
          }
          else if (n > 99) {
               if (n / 100 != n % 10) p = 0;
          }
          else if (n > 9) {
               if (n / 10 != n % 10) p = 0;
          }

          if (p) {
               printf("yes\n");
          }
          else printf("no\n");
     }
     return 0;
}