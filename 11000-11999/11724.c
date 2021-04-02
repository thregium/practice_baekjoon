#include <stdio.h>

/*
���� : ���⼺�� ���� �׷����� �־��� �� �� �׷����� ���� ����� ������ ���Ѵ�.

�ذ� ��� : �׷����� ������ �ϳ��� Ž���ϸ� Ž������ ���� ���� ��ҿ� ���� ��� DFS�� ���� �ش� ���� ��Ҹ� Ž���ϰ�, ������ 1 �߰��Ѵ�. Ž���� ����Ǹ� ������ ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, DFS
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