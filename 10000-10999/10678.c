#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 16)개의 지역이 있고, 각 지역 사이에는 M개의 통로가 있다. 각 통로는 지역 번호가 증가하는 방향으로 일방통행이다.
이때, 통로별로 두 명이 이동하는 시간이 각각 주어질 때, 1번 통로에서 출발해 N번 통로에 동시에 도착하는 방법이 있는지
확인하고 있다면 그 중 가장 빠른 것의 소요시간을 구한다. 없다면 -1을 출력한다.

해결 방법 : 1번 지역부터 재귀적으로 이동 가능한 모든 경로를 이용해본다. N번 지역에 도착하면 해당 지역에 도착한
두 명의 소요 시간을 각각 저장한다. 모든 경로를 확인하면 두 명의 소요 시간 중 겹치는 것이 있는지 확인하고
있다면 그러한 것 가운데 가장 작은 것을 출력하고 없다면 -1을 출력하면 된다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2015J B4번
*/

int bessie[32][32], elsie[32][32];
char bchk[16384], echk[16384];
int best = INF;

void track(int n, int s, int x, int b, int e) {
    if (x == n) {
        bchk[b] = 1;
        echk[e] = 1;
    }
    for (int i = x + 1; i <= n; i++) {
        if (bessie[x][i]) {
            track(n, s, i, b + bessie[x][i], e + elsie[x][i]);
        }
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("meeting.in", "r");
        fo = fopen("meeting.out", "w");
    }
    //freopen("meeting.in", "r", stdin);
    //freopen("meeting.out", "w", stdout);
    int n, m, a, b, c, d;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        bessie[a][b] = c;
        elsie[a][b] = d;
    }
    track(n, 1, 1, 0, 0);
    for (int i = 1; i <= 16000; i++) {
        if (bchk[i] && echk[i]) {
            best = i;
            break;
        }
    }
    if (best == INF) printf("%s", "IMPOSSIBLE");
    else printf("%d", best);
    return 0;
}