#include <stdio.h>

/*
���� : N ������ �� �ڿ����� ���� ��� ������ ������ ������������ K��° ���� ������ ���Ѵ�. N�� K�� �־�����.

�ذ� ��� : ���� m���� ���� ������ ������ O(N)�� �ð� �� ���� �� �����Ƿ� ���� m���� ���� ������ ���� ���ذ��� �̺� Ž���� ����Ͽ� K��° ���� ���Ѵ�.

�ֿ� �˰��� : �̺� Ž��
*/

long long int small(long long a, long long b) {
     return a < b ? a : b;
}

int main(void) {
     int n, k;
     scanf("%d%d", &n, &k);

     long long int l = 0, h = (long long)n * n, m, c;
     while (l + 1 < h) {
          m = (l + h) / 2;
          c = 0;
          for (int i = 1; i <= n; i++) {
               c += small(n, m / i);
          }

          if (c < k) {
               l = m;
          }
          else {
               h = m;
          }
     }
     printf("%d", h);
     return 0;
}