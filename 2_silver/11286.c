#include <stdio.h>
#include <math.h>

/*
문제 : 절댓값을 기준으로 한 힙을 구현한다. 단, 절댓값이 같은 경우 더 작은 수가 우선이다.

해결 방법 : 절댓값 힙을 구현한다. 조건이 여러가지이므로 함수를 이용하는 것이 좋다.

주요 알고리즘 : 자료구조, 힙
*/

int h[1048576];
int hs = 0;

int main(void) {
     int n, tmp;
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) {
          scanf("%d", &h[hs + 1]);
          if (h[hs + 1]) {
               hs++;
               for (int j = hs; j > 1; j /= 2) {
                    if (abs(h[j / 2]) > abs(h[j]) || (abs(h[j / 2]) == abs(h[j]) && h[j / 2] > h[j])) {
                         tmp = h[j / 2];
                         h[j / 2] = h[j];
                         h[j] = tmp;
                    }
                    else break;
               }
          }
          else {
               if (!h[1]) {
                    printf("0\n");
                    continue;
               }
               printf("%d\n", h[1]);
               h[1] = h[hs];
               h[hs] = 0;
               hs--;
               for (int j = 1; j < hs;) {
                    if (h[j * 2] && (abs(h[j * 2]) < abs(h[j * 2 + 1]) || (abs(h[j * 2]) == abs(h[j * 2 + 1]) && h[j * 2] < h[j * 2 + 1])|| !h[j * 2 + 1]) && (abs(h[j * 2]) < abs(h[j]) || (abs(h[j * 2]) == abs(h[j]) && h[j * 2] < h[j]))) {
                         tmp = h[j * 2];
                         h[j * 2] = h[j];
                         h[j] = tmp;
                         j *= 2;
                    }
                    else if (h[j * 2 + 1] && (abs(h[j * 2 + 1]) < abs(h[j]) || (abs(h[j * 2 + 1]) == abs(h[j]) && h[j * 2 + 1] < h[j]))) {
                         tmp = h[j * 2 + 1];
                         h[j * 2 + 1] = h[j];
                         h[j] = tmp;
                         j = j * 2 + 1;
                    }
                    else break;
               }
          }
     }
     return 0;
}