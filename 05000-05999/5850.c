#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 100 * 100 좌표 내에 짚 더미가 상하좌우로 연결된 형태로 주어질 때, 짚 더미의 둘레를 구한다.
단, 짚 더미의 안쪽에 있는 구멍은 둘레에 포함되지 않는다.

해결 방법 : 짚의 바깥쪽 부분부터 플러드필을 하면 안쪽 구멍은 무시하며 둘레를 구할 수 있다.
플러드필을 해 나가다가 짚이 있는 부분을 발견하면 둘레 값을 1 올리면 플러드필이 끝났을 때의 둘레 값이 답이 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : USACO 2013F B3번
*/

int hay[128][128], vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int perm = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 128 || y >= 128) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

int dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
        if (hay[x + dxy[i][0]][y + dxy[i][1]]) {
            perm++;
            continue;
        }
        else dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("perimeter.in", "r");
        fo = fopen("perimeter.out", "w");
    }
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        hay[x][y] = 1;
    }
    dfs(0, 0);
    printf("%d", perm);
    return 0;
}