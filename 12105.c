#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
���� : ���̰� n�� ������ �־��� �� �� ������ �κ� ���� ��� ���� �� �����ϴ� ������ ���̸� ���Ѵ�. (N <= 1000000)

�ذ� ��� : ���ο� �κ� ������ �����, �� ������ �� �� ������ �� ū ���� ������ ������ �� �ڿ� ����ִ´�.
�� ũ�� ���� ���� ������ �� ������ ���� ���� ù ���� ��ġ�� �� ���� ����ִ´�. N�� ũ�� ������ ���� ã�� ���� �̺� Ž���� ����Ѵ�.
������ �������� �����ϸ� ���� �� �����ϴ� ������ ���������.

�ֿ� �˰��� : �̺� Ž��
*/

int a[1048576], p[1048576];
int d[1048576];
int x = 1, z = 0;

int main(void) {
     int n;
     int t;
     int l, h, m, k;
     
     /*
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &a[i]);
     }
     */
     srand(time(NULL));
     
     
     n = 10000;
     for (int tt = 0; tt < 10; tt++) {

          x = 1;
          z = 0;

          int ttt = 1;
          for (int i = 0; i < n; i++) {
               a[i] = rand();
               srand(rand() + i * 39);
          }

          int r = 0;
          for (int i = 0; i < n; i++) {
               t = 0;
               for (int j = 0; j < i; j++) {
                    if (a[j] < a[i] && d[j] > t) t = d[j];
               }
               d[i] = t + 1;
               if (d[i] > r) r = d[i];
          }

          p[0] = a[0];
          for (int i = 1; i < n; i++) {
               k = a[i];
               l = 0;
               h = x - 1;
               if (k > p[x - 1]) {
                    p[x] = k;
                    z = k;
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

          if (r != x) {
               for (int i = 0; i < n; i++) printf("%d ", a[i]);
               printf("\n%d : %d\n\n", r, x);
          }
     }
     


     /*
     //n = 1000000;
     //for (int i = 0; i < 1000000; i++) a[i] = 10;
     p[0] = a[0];
     for (int i = 1; i < n; i++) {
          k = a[i];
          l = 0;
          h = x - 1;
          if (k > p[x - 1]) {
               p[x] = k;
               z = k;
               x++;
               continue;
          }

          while (l < h) {
               m = (l + h) / 2;

               if (p[m] < k) {
                    l = m + 1;
               }
               //else if (p[m] == k + 1) break;
               else {
                    h = m - 1;
               }
          }

          if (p[l] == k) continue;
          else {
               if (k > p[l]) l++;
               p[l] = k;
          }
     }
     
     printf("%d", x);
     */
     

     return 0;
}