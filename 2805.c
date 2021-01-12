#include <stdio.h>

/*
���� : N�׷��� ������ ���� ���� �̻��� �߶� M������ ���縦 �����Ϸ��� �Ѵ�. ������ ���̰� �־��� �� M���� �̻��� ���縦 ���� �� �ִ� �ִ� ���̸� ���Ѵ�.

�ذ� ��� : ������ ���� ��� ���� �� ���� �������� ��� ������ ���̺��� ���� ������ ���� ���̸� ������ ���̿��� �� ���� ���� ���� M�� ���Ͽ� �̺� Ž���� ���� ���̸� ã�´�.

�ֿ� �˰��� : �̺� Ž��
*/

int forest[1048576];

int main(void) {
     int n, m, b = 0;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < n; i++) {
          scanf("%d", &forest[i]);
          if (forest[i] > b) b = forest[i];
     }

     int lo = 0, hi = b + 1, mid;
     long long int wood;
     while (lo + 1 < hi) {
          mid = (lo + hi) / 2;
          wood = 0;
          for (int i = 0; i < n; i++) {
               wood += (forest[i] - mid > 0 ? forest[i] - mid : 0);
          }

          if (wood < m) {
               hi = mid;
          }
          else {
               lo = mid;
          }
     }
     printf("%d", lo);
     return 0;
}