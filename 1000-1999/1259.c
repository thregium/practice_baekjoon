#include <stdio.h>

/*
���� : 5�ڸ� ������ ���� �־��� �� �� ���� �Ӹ���Ҽ����� �˻��Ѵ�.

�ذ� ��� : �ڸ����� ���� ��츦 ������ ���Ѵ�.

�ֿ� �˰��� : ����, ����?

��ó : NZPC 2006 B��
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