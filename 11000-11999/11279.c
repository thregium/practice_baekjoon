#include <stdio.h>

/*
문제 : 최대 힙을 구현하는 프로그램을 만든다.

해결 방법 : 최대 힙을 구현한다.

주요 알고리즘 : 자료구조, 힙
*/

int h[102400];
int hs = 0;

int main(void) {
     int n, tmp;
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) {
          scanf("%d", &h[hs + 1]);
          if (h[hs + 1]) {
               hs++;
               for (int j = hs; j > 1; j /= 2) {
                    if (h[j / 2] < h[j]) {
                         tmp = h[j / 2];
                         h[j / 2] = h[j];
                         h[j] = tmp;
                    }
                    else break;
               }
          }
          else {
               if (!h[hs]) {
                    printf("0\n");
                    continue;
               }
               printf("%d\n", h[1]);
               h[1] = h[hs];
               h[hs] = 0;
               hs--;
               for (int j = 1; j < hs;) {
                    if (h[j * 2] > h[j * 2 + 1] && h[j * 2] > h[j]) {
                         tmp = h[j * 2];
                         h[j * 2] = h[j];
                         h[j] = tmp;
                         j *= 2;
                    }
                    else if (h[j * 2 + 1] > h[j]) {
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