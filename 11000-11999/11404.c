#include <stdio.h>
#define INF 999999999

/*
���� : �׷����� ���� ����� �־��� �� ��� ���� i, j�� ���� ���� i���� j���� �ִܰŸ��� ���Ѵ�. (N <= 100)

�ذ� ��� : �÷��̵�-�ͼ� �˰����� �̿��Ͽ� �ִܰŸ��� ���Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-�ͼ�
*/

long long g[128][128];

long long small(long long a, long long b) {
     return a < b ? a : b;
}

int main(void) {
     int n, m, a, b, c;
     scanf("%d", &n);
     scanf("%d", &m);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               g[i][j] = INF;
          }
     }
     for (int j = 0; j < m; j++) {
          scanf("%d %d %d", &a, &b, &c);
          if(g[a - 1][b - 1] > c) g[a - 1][b - 1] = c;
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
               if (i == j || g[i][j] >= INF) printf("0 ");
               else printf("%d ", g[i][j]);
          }
          printf("\n");
     }
     return 0;
}