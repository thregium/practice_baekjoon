#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
���� : �ּ� ���� �����ϴ� ���α׷��� �����.

�ذ� ��� : �ּ� ���� �����Ѵ�. �̶� NULL ó���� �����ؾ� �Ѵ�.

�ֿ� �˰��� : �ڷᱸ��, ��
*/

int h[1048576];
int hs = 0;
int last = 0;

int main(void) {
     int n, tmp;
     scanf("%d", &n);
     srand(time(NULL));
     for (int i = 1; i <= n; i++) {
          /*
          h[hs + 1] = rand() % 2 ? rand() : 0;
          printf("#%d\n", h[hs + 1]);
          */
          /*
          if (i <= n / 2) {
               h[hs + 1] = rand() * 65536 + rand();
               srand(rand() + i * 39);
               //printf("%d\n", h[hs + 1]);
          }
          else h[hs + 1] = 0;
          */
          //scanf("%d", &h[hs + 1]);
          if (h[hs + 1]) {
               hs++;
               for (int j = hs; j > 1; j /= 2) {
                    if (h[j / 2] > h[j]) {
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
               
               if (last > h[1]) {
                    printf("!!error!!");
                    break;
               }
               else last = h[1];
               
               /*
               last = 65536;
               for (int j = 1; j <= hs; j++) {
                    printf("%d ", h[j]);
                    if (h[j] < last) last = h[j];
               }
               printf("\n");
               if (last != h[1]) {
                    printf("!!error!!");
                    break;
               }
               */
               h[1] = h[hs];
               h[hs] = 0;
               hs--;
               for (int j = 1; j < hs;) {
                    if (h[j * 2] && (h[j * 2] < h[j * 2 + 1] || !h[j * 2 + 1]) && h[j * 2] < h[j]) {
                         tmp = h[j * 2];
                         h[j * 2] = h[j];
                         h[j] = tmp;
                         j *= 2;
                    }
                    else if (h[j * 2 + 1] && h[j * 2 + 1] < h[j]) {
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