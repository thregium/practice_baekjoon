#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 11)개의 정점으로 이루어진 양방향 연결 그래프의 최대 색칠 가능 수를 구한다.
간선으로 이어진 두 정점은 다른 색으로 칠해져야 한다.

해결 방법 : 우선 DFS 순서대로 그래프를 탐색한 다음, 그 순서를 기억해 둔다.
그리고 이 번호 순서대로 그래프의 정점들을 칠해나가면 된다. 현재까지 나온 최대 색상 수 + 1보다
큰 색으로 칠할 필요가 없고 최적값 이상의 색상 수가 나오면 바로 탐색을 종료하여
시간을 좀더 절약할 수 있다.

주요 알고리즘 : 그래프 이론, 백트래킹

출처 : VTH 2015 H번
*/

char buff[1024];
int ed[16][16], dfsn[16], dfsv[16], color[16];
int dcnt = 0, best = 103000;

void dfs(int x) {
    dfsn[dcnt] = x;
    dfsv[x] = ++dcnt;
    for (int i = 0; i < 16; i++) {
        if (!ed[x][i]) continue;
        if (dfsv[i]) continue;
        dfs(i);
    }
}

void track(int n, int x, int ccnt) {
    if (ccnt >= best) return;
    if (x == n) {
        if (ccnt < best) best = ccnt;
        return;
    }
    int tmp;
    for (int i = 1; i <= ccnt + 1; i++) {
        color[dfsn[x]] = i;
        tmp = 1;
        for (int j = 0; j < n; j++) {
            if (!ed[dfsn[x]][j] || dfsv[j] > x) continue;
            if (color[dfsn[x]] == color[j]) {
                tmp = 0;
                break;
            }
        }
        if (tmp) track(n, x + 1, i > ccnt ? ccnt + 1 : ccnt);
    }
}

int main(void) {
    int n, x;
    char* c;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(buff, 1013, stdin);
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        c = strtok(buff, " ");
        while (c) {
            x = strtoll(c, NULL, 10);
            ed[i][x] = 1;
            c = strtok(NULL, " ");
        }
    }
    dfs(0);
    track(n, 0, 0);
    if (best > 25) return 1;
    printf("%d", best);
    return 0;
}