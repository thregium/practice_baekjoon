#include <stdio.h>

/*
문제 : N * M(N, M <= 1000) 크기의 격자에서 각 칸마다 이동하는 방향이 주어질 때,
어떤 칸에서 출발해도 선택한 칸 중 하나에 도달할 수 있도록 칸들을 선택하기 위해
골라야 하는 칸의 최소 개수를 구한다.

해결 방법 : 유니온-파인드를 통해 각 칸에서 이동하는 칸들을 하나의 연결 요소로 묶은 다음,
연결 요소의 개수를 구하면 된다.

주요 알고리즘 : 그래프 이론, 유니온 파인드

출처 : 한양대E 2018Z F번
*/

char s[1024][1024], vis[1048576];
int g[1048576];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'U') uni((i << 10) + j, ((i - 1) << 10) + j);
            else if (s[i][j] == 'R') uni((i << 10) + j, (i << 10) + j + 1);
            else if (s[i][j] == 'D') uni((i << 10) + j, ((i + 1) << 10) + j);
            else if (s[i][j] == 'L') uni((i << 10) + j, (i << 10) + j - 1);
            else return 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[find((i << 10) + j)]) {
                vis[find((i << 10) + j)] = 1;
                r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}