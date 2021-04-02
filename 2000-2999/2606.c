#include <stdio.h>

/*
문제 : 여러 컴퓨터의 네트워크를 입력받았을 때 1번 컴퓨터가 바이러스에 걸리면 연결된 네트워크를 통해 같이 바이러스에 걸리는 컴퓨터의 수를 출력한다.

해결 방법 : 네트워크를 전부 입력받은 후 1번 컴퓨터부터 시작해서 컴퓨터들 사이에 네트워크가 존재하는 경우 그 컴퓨터로 간 후 변수를 1 올린다.
이미 방문한 컴퓨터는 다시 방문하지 않는다. 방문이 끝나면 변수를 출력한다.

주요 알고리즘 : 그래프, 깊이 우선 탐색
*/

int link[128][128] = { 0, };
int visited[128] = { 0, };
int v = 0;

void virus(int n, int a) {
     if (visited[a]) return;
     visited[a] = 1;
     v++;
     for (int i = 1; i <= n; i++) {
          if (link[a][i]) virus(n, i);
     }
}

int main(void) {
     int n, l, a, b;
     scanf("%d%d", &n, &l);
     for (int i = 0; i < l; i++) {
          scanf("%d %d", &a, &b);
          link[a][b] = 1;
          link[b][a] = 1;
     }
     virus(n, 1);
     printf("%d", v - 1);
     return 0;
}