#include <stdio.h>
#define INF 99999999999

/*
문제 : N(N <= 1000)개의 정점으로 이루어진 그래프가 있을 때, 특정한 점으로 갔다가 다시 돌아오는 거리가 가장 작은 정점을 구한다.

해결 방법 : N이 꽤 큰 편이긴 하지만 플로이드-워셜에서 이미 i에서 j로 가는 거리가 무한대인 경우를 후보에서 제외하면 시간 제한 내 풀 수 있다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜

출처 : USACO 2007/02 S3번
*/

long long g[1024][1024];

long long small(long long a, long long b) {
     return a < b ? a : b;
}

int main(void) {
     int n, m, x, a, b, c;
     long long longest = 0;
     scanf("%d %d %d", &n, &m, &x);
     for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) {
               g[i][j] = INF;
          }
     }
     for (int j = 1; j <= m; j++) {
          scanf("%d %d %d", &a, &b, &c);
          g[a][b] = c;
     }

     for (int j = 1; j <= n; j++) {
          for (int i = 1; i <= n; i++) {
          	if(g[i][j] == INF) continue;
               for (int k = 1; k <= n; k++) {
                    g[i][k] = small(g[i][k], g[i][j] + g[j][k]);
               }
          }
     }
     for (int i = 1; i <= n; i++) {
         if(i == x) continue;
          if(g[i][x] + g[x][i] > longest && g[i][x] < INF && g[x][i] < INF) longest = g[i][x] + g[x][i];
     }
     printf("%lld", longest);
     return 0;
}