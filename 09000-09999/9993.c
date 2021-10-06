#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N * M(N, M <= 1000) 크기의 격자가 주어진다. 이 격자의 각 칸마다 대각선으로 놓인 거울들이 있다. 이때, 격자의 바깥에서
광선을 수평 또는 수직으로 쏜다면 거울을 최대 몇 개 맞출 수 있는지 구한다.

해결 방법 : 거울 바깥에서 한 쪽으로 광선을 쏘면 그 광선은 다른 쪽 바깥으로 나올 것이다. 그곳으로 가는 경로를 따라가면,
그 경로와 겹치는 경로는 없다는 사실을 발견할 수 있다. 따라서, 모든 칸에 대해 겹치는 경로가 없기 때문에
모든 곳에서 시작하는 경로의 합은 최대 N * M * 2이고, 모든 경로를 찾아보더라도 시간 내에 돌아갈 수 있다.

주요 알고리즘 : 브루트 포스, 그래프 이론

출처 : USACO 2014F B1번
*/

char mirror[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int reflect(int x, int y, int d) {
    int st = 0;
    while (x >= 0 && x < n && y >= 0 && y < m) {
        if (mirror[x][y] == '/') d = 3 - d;
        else d += ((d & 1) ? -1 : 1);
        x += dxy[d][0];
        y += dxy[d][1];
        st++;
    }
    return st;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("mirror.in", "r");
        fo = fopen("mirror.out", "w");
    }
    int r = 0, step;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", mirror[i]);
    }

    for (int i = 0; i < n; i++) {
        step = reflect(i, 0, 0);
        if (step > r) r = step;
        step = reflect(i, m - 1, 2);
        if (step > r) r = step;
    }
    for (int i = 0; i < m; i++) {
        step = reflect(0, i, 1);
        if (step > r) r = step;
        step = reflect(n - 1, i, 3);
        if (step > r) r = step;
    }
    printf("%d", r);
    return 0;
}