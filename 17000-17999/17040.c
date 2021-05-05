#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100)개의 정점을 가진 그래프에서 인접한 정점의 색을 다르게 하려고 한다. 이때 정점을 칠하는 방법 중 사전순으로 가장 앞선 것을 찾는다.
단, 각 정점은 최대 3개까지의 간선만 가진다.

해결 방법 : 먼저 각 정점에 연결된 다른 정점들을 전부 확인한다. 그 다음, 정점들을 번호 순서대로 돌면서 인접한 정점에 없는 색 중
가장 작은 번호를 갖는 색으로 칠하면 된다.

주요 알고리즘 : 그래프 이론, 그리디 알고리즘

출처 : USACO 2019F B2번
*/

int link[128][3], r[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("revegetate.in", "r");
        fo = fopen("revegetate.out", "w");
    }
    int n, m, a, b, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        for (int j = 0; j < 3; j++) {
            if (!link[a][j]) {
                link[a][j] = b;
                break;
            }
        }
        for (int j = 0; j < 3; j++) {
            if (!link[b][j]) {
                link[b][j] = a;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            t = 1;
            for (int k = 0; k < 3; k++) {
                if (r[link[i][k]] == j) {
                    t = 0;
                    break;
                }
            }
            if (t) {
                r[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d", r[i]);
    }
    return 0;
}