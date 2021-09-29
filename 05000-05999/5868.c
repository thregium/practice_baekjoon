#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 격자판 위에 N(N <= 500)개의 울타리와 C(C <= 500)마리의 소들이 있다. 울타리는 X축 또는 Y축과 평행하고
끝과 끝이 서로 연결되어 있다. 소들이 울타리를 지나지 않고 서로 만날 수 있다면 같은 집합에 있다고 할 때,
가장 큰 집합에 있는 소의 마릿수를 구한다. 소와 울타리의 좌표 범위는 1 이상 10^6 이하의 자연수이다.

해결 방법 : 울타리의 범위와 각 소의 위치를 기록한 다음 플러드필을 통해 소의 집합들을 구하면 된다.
그런데, 좌표의 범위가 매우 넓기 때문에 좌표 압축을 진행해야 한다. 좌표 압축을 할 때 좌표를 1씩 옮기면 좌표가 1 차이 나는 경우를
제대로 확인할 수 없으므로 좌표를 2씩 옮기도록 한다.
좌표가 커야 (N * 2 + C) * 2 범위 안에는 있음이 보장되므로 이 범위 안의 울타리가 아닌 곳들을 돌며
플러드필을 하면서 소가 가장 많은 집합의 크기를 구하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 좌표 압축

출처 : USACO 2012D B3번
*/

int fence[512][4], cow[512][2], xpos[1536][3], ypos[1536][3];
char map[3072][3072], vis[3072][3072];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int xsz, ysz;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x > xsz + 1 || y > ysz + 1) return 0;
    if (vis[x][y] || map[x][y] == 1) return 0;
    return 1;
}

int dfs(int x, int y) {
    int r = (map[x][y] == 2);
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) r += dfs(x + dxy[i][0], y + dxy[i][1]);
    }
    return r;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("crazy.in", "r");
        fo = fopen("crazy.out", "w");
    }
    int n, c, r = 0, t;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &fence[i][0], &fence[i][1], &fence[i][2], &fence[i][3]);
        xpos[i][0] = fence[i][0]; //임시 배열에 값들을 옮긴다
        xpos[i][1] = i;
        ypos[i][0] = fence[i][1];
        ypos[i][1] = i;
        xpos[n + i][0] = fence[i][2];
        xpos[n + i][1] = n + i;
        ypos[n + i][0] = fence[i][3];
        ypos[n + i][1] = n + i;
    }
    for (int i = 0; i < c; i++) {
        scanf("%d %d", &cow[i][0], &cow[i][1]);
        xpos[n * 2 + i][0] = cow[i][0];
        xpos[n * 2 + i][1] = n * 2 + i;
        ypos[n * 2 + i][0] = cow[i][1];
        ypos[n * 2 + i][1] = n * 2 + i;
    }

    qsort(xpos, n * 2 + c, sizeof(int) * 3, cmp1); //x좌표와 y좌표를 서로 다른 배열로 각각 정렬한다.
    qsort(ypos, n * 2 + c, sizeof(int) * 3, cmp1);

    xpos[0][2] = 1, ypos[0][2] = 1;
    for (int i = 1; i < n * 2 + c; i++) {
        if (xpos[i][0] == xpos[i - 1][0]) xpos[i][2] = xpos[i - 1][2];
        else xpos[i][2] = xpos[i - 1][2] + 2; //서로 다른 값이면 2를 더하고 같은 값이면 그대로 간다.
        if (ypos[i][0] == ypos[i - 1][0]) ypos[i][2] = ypos[i - 1][2];
        else ypos[i][2] = ypos[i - 1][2] + 2;
    }
    for (int i = 0; i < n * 2 + c; i++) {
        if (xpos[i][1] < n) fence[xpos[i][1]][0] = xpos[i][2]; //좌표 압축한 값들을 원래 배열로 옮겨준다.
        else if (xpos[i][1] < n * 2) fence[xpos[i][1] - n][2] = xpos[i][2];
        else cow[xpos[i][1] - n * 2][0] = xpos[i][2];
        if (ypos[i][1] < n) fence[ypos[i][1]][1] = ypos[i][2];
        else if (ypos[i][1] < n * 2) fence[ypos[i][1] - n][3] = ypos[i][2];
        else cow[ypos[i][1] - n * 2][1] = ypos[i][2];
    }

    for (int i = 0; i < n; i++) {
        if (fence[i][0] > fence[i][2]) swap(&fence[i][0], &fence[i][2]); //이후의 값이 더 작을 수 있으므로 바꿔준다.
        if (fence[i][1] > fence[i][3]) swap(&fence[i][1], &fence[i][3]);

        for (int x = fence[i][0]; x <= fence[i][2]; x++) {
            for (int y = fence[i][1]; y <= fence[i][3]; y++) {
                map[x][y] = 1; //울타리를 추가한다.
            }
        }
    }
    for (int i = 0; i < c; i++) {
        map[cow[i][0]][cow[i][1]] = 2; //소들의 위치를 기록한다.
    }

    xsz = xpos[n * 2 + c - 1][2]; //지도의 크기를 좌표 압축한 가장 큰 값으로 설정한다.
    ysz = ypos[n * 2 + c - 1][2];
    for (int i = 0; i <= xsz + 1; i++) {
        for (int j = 0; j <= ysz + 1; j++) {
            if (!vis[i][j] && map[i][j] != 1) {
                t = dfs(i, j); //아직 탐색하지 않은 칸에 대해 해당 칸이 있는 집합의 소 마릿수를 구한다.
                if (t > r) r = t;
            }
        }
    }
    printf("%d", r);
    return 0;
}