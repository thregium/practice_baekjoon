#include <stdio.h>

/*
문제 : 방향성이 없는 그래프가 주어질 때 이 그래프의 연결 요소의 갯수를 구한다.

해결 방법 : 그래프의 노드들을 하나씩 탐색하며 탐색하지 않은 연결 요소에 속한 경우 DFS를 통해 해당 연결 요소를 탐색하고, 갯수를 1 추가한다. 탐색이 종료되면 갯수를 출력한다.

주요 알고리즘 : 그래프 이론, DFS
*/

int graph[1024][1024], visited[1024];

void visit(int a) {
     if (!visited[a]) {
          visited[a] = 1;
          for (int i = 1; i <= graph[a][0]; i++) {
               if (!visited[graph[a][i]]) visit(graph[a][i]);
          }
     }
}

int main(void) {
     int n, m, u, v, l = 0;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < m; i++) {
          scanf("%d %d", &u, &v);
          graph[u][graph[u][0] + 1] = v;
          graph[u][0]++;
          graph[v][graph[v][0] + 1] = u;
          graph[v][0]++;
     }
     for (int i = 1; i <= n; i++) {
          if (!visited[i]) {
               visit(i);
               l++;
          }
     }
     printf("%d", l);
     return 0;
}