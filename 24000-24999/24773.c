#include <stdio.h>

/*
문제 : P(P <= 100)개의 정점과 C(C <= 5000)개의 간선으로 이루어진 양방향 연결 그래프가 주어질 때,
간선 하나를 제거하여 연결 그래프가 아니게 만들 수 있는 지 구한다.

해결 방법 : P와 C의 값이 작으므로 모든 간선을 하나씩 끊어보면서 연결그래프인 지 여부를 확인해서
하나라도 아닌 것이 있는 지 확인하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 브루트 포스

출처 : VTH 2014 I번
*/

int ed[128][128], edn[5120][2], vis[128];

void dfs(int x, int a, int b) {
    vis[x] = 1;
    for (int i = 1; i <= ed[x][0]; i++) {
        if ((x == a && ed[x][i] == b) || (x == b && ed[x][i] == a)) continue;
        if (vis[ed[x][i]]) continue;
        dfs(ed[x][i], a, b);
    }
}

int main(void) {
    int p, c, r;
    //freopen("E:\\PS\\High School\\VTH\\2014\\birthday.in", "r", stdin);
    //freopen("E:\\PS\\High School\\VTH\\2014\\birthday_t.out", "w", stdout);
    while (1) {
        scanf("%d %d", &p, &c);
        if (p == 0) break;
        for (int i = 0; i < c; i++) {
            scanf("%d %d", &edn[i][0], &edn[i][1]);
            ed[edn[i][0]][++ed[edn[i][0]][0]] = edn[i][1];
            ed[edn[i][1]][++ed[edn[i][1]][0]] = edn[i][0];
        }
        r = 1;
        for (int i = 0; i < c; i++) {
            dfs(0, edn[i][0], edn[i][1]);
            for (int j = 0; j < p; j++) {
                if (!vis[j]) r = 0;
                vis[j] = 0;
            }
            if (!r) break;
        }
        printf("%s\n", r ? "No" : "Yes");
        for (int i = 0; i < p; i++) ed[i][0] = 0;
    }
    return 0;
}
