#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100000)개의 노드들로 이루어진 트리에서 트리의 연결 상태가 주어질 때, 한 정점에서 인접한 모든 노드의 색이 다르게 하려면 필요한 최소 색의 수를 구한다.

해결 방법 : 가장 연결된 노드가 많은 정점에서 인접한 모든 노드의 색을 다르게 하면 된다. 따라서 가장 연결된 노드가 많은 정점에 연결된 노드의 수 + 1과 같다.

주요 알고리즘 : 그리디 알고리즘, 트리

출처 : USACO 2019J S1번
*/

int cnt[103000];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("planting.in", "r");
        fo = fopen("planting.out", "w");
    }
    int n, a, b, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &a, &b);
        cnt[a]++;
        cnt[b]++;
        if (cnt[a] > r) r = cnt[a];
        if (cnt[b] > r) r = cnt[b];
    }
    printf("%d", r + 1);
    return 0;
}