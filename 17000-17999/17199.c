#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100)개의 정점으로 이루어진 유향 트리에서 모든 정점에서 도달 가능한 노드가 있는지 찾고 있다면 그 중 가장 작은 값을 출력한다.

해결 방법 : 그래프에 사이클이 존재하지 않으므로 그 정점에서 출발하는 다른 노드에서는 그 정점으로 다시 돌아올 수 없다.
또한, 출발하는 정점이 없는 노드가 여러개인 경우 서로간에는 도달이 불가능하다. 따라서, 출발하는 정점이 없는 노드가 1개인 경우
그 노드가 모든 정점에서 도달 가능한 노드이지만 그러한 노드가 2개 이상인 경우 모든 정점에서 도달 가능한 노드는 없다.
그러한 노드가 0개인 경우는 그래프 특성상 존재가 불가능하다.

주요 알고리즘 : 그래프 이론

출처 : USACO 2019O B2번
*/

int cnt[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("factory.in", "r");
        fo = fopen("factory.out", "w");
    }
    int n, a, b, r = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        cnt[a]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) r++;
    }
    if (r == 1) {
        for (int i = 1; i <= n; i++) {
            if (!cnt[i]) {
                printf("%d", i);
            }
        }
    }
    else printf("%d", -1);
    return 0;
}