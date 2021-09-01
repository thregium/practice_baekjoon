#include <stdio.h>

/*
문제 : N(N <= 10000)개의 정점을 가진 그래프가 있고, 각 정점에는 가중치가 있다.
각 그래프의 연결 요소에 대한 가중치의 최솟값의 합을 구한다.

해결 방법 : 유니온 파인드를 통해 간선이 추가될 때 마다 대푯값을 가중치가 작은 쪽으로 옮긴다.
이를 반복하면 모든 정점들이 연결요소별로 집합으로 분리되며, 각각의 대표 정점은 가중치의 최솟값이 된다.
이제 각 연결요소마다 해당 값들을 합하면 된다.

주요 알고리즘 : 자료 구조, 유니온 파인드

출처 : 서강대 2018M B번
*/

int g[10240], money[10240];

int find(int x) {
    if (!g[x]) return x;
    return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, m, k, v, w;
    long long r = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &money[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &v, &w);
        if (money[find(v)] < money[find(w)]) uni(v, w);
        else uni(w, v);
    }
    for (int i = 1; i <= n; i++) {
        if (!money[find(i)]) continue;
        r += money[find(i)];
        money[find(i)] = 0;
    }
    if (r <= k) printf("%lld", r);
    else printf("Oh no");
    return 0;
}