#include <stdio.h>
#define INF 999999999

/*
문제 : 그래프의 인접 행렬이 주어질 때 모든 정점 i, j에 대해 정점 i에서 j로의 최단거리를 구한다. (N <= 100)

해결 방법 : 플로이드-와샬 알고리즘을 이용하여 최단거리를 구한다.

주요 알고리즘 : 그래프 이론, 플로이드-와샬
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