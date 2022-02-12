#include <stdio.h>
#include <stdlib.h>

/*
문제 : 1부터 N(N <= 4 * 10^6)까지의 자연수가 적힌 카드 가운데 M(M <= N)개의 카드가 주어질 때,
K(K <= 10000)개의 쿼리에 응답한다.
X가 주어질 때, X보다 큰 가장 작은 카드를 고르고, 그 카드를 버린다.

해결 방법 : 각 카드들을 정렬한 다음, 이분 탐색을 통해 고를 카드를 찾으면 된다.
단, N과 M이 매우 크기 때문에 이 과정에서 최적화가 많이 필요하다. 정렬을 카운팅 소트로 하거나
분리 집합을 사용하거나 fast io 등을 이용하는 등의 방법을 사용해야 한다.

주요 알고리즘 : 최적화, 정렬, 이분 탐색

출처 : 서강대 2018M F번
*/

int card[4194304], g[4194304];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int lb(int* a, int n, int p) {
    int l = 1, h = n, m;
    while (l < h) {
        m = (l + h) >> 1;
        if (a[m] >= p) h = m;
        else l = m + 1;
    }
    return l;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, k, x, y;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        card[x] = 1;
    }
    y = 1;
    for (int i = 1; i <= n; i++) {
        if (card[i]) {
            card[y++] = i;
        }
    }
    if (y != m + 1) return 1;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        y = lb(card, m, x + 1);
        printf("%d\n", card[find(y)]);
        uni(find(y) + 1, y);
    }
    return 0;
}