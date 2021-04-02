#include <stdio.h>
#define INF 999999999

/*
���� : �׷����� ���� ����� �־��� �� ��� ���� i, j�� ���� ���� i���� j�� ���� ��ΰ� �ִ� �� ���Ѵ�. (N <= 100)

�ذ� ��� : �÷��̵�-�ͼ� �˰����� �̿��Ͽ� �ִܰŸ��� ���ϰ�, �ִܰŸ��� ���Ѵ��� ������ ��ΰ� ���ٰ� �Ǵ��Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-�ͼ�
*/

long long g[128][128];

long long small(long long a, long long b) {
     return a < b ? a : b;
}

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               scanf("%lld", &g[i][j]);
               if (g[i][j] == 0) g[i][j] = INF;
          }
     }

     for (int j = 0; j < n; j++) {
          for (int i = 0; i < n; i++) {
               for (int k = 0; k < n; k++) {
                    g[i][k] = small(g[i][k], g[i][j] + g[j][k]);
               }
          }
     }
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               if (g[i][j] >= INF) printf("0 ");
               else printf("1 ");
          }
          printf("\n");
     }
     return 0;
}