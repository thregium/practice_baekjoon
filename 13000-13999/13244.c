#include <stdio.h>

/*
문제 : 주어진 그래프가 트리인지 판별한다.

해결 방법 : 주어진 그래프에 사이클이 있다면 트리가 아니다. 이것은 유니온 파인드를 통해 쉽게 해결 가능하다.
또한, 모든 그래프가 하나의 연결 요소로 이루어져야 하는데, 이 역시 유니온 파인드로 해결 가능하다.

주요 알고리즘 : 그래프 이론, 트리, 유니온 파인드

출처 : AIPO 2016F 5번
*/

int g[1024];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    g[find(x)] = find(y);
}

int main(void) {
    int t, n, m, a, b, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d%d", &n, &m);
        r = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            if (find(a) == find(b)) r = 1; //연결한 간선이 이미 같은 집합인 경우 트리가 아니다.
            else uni(a, b);
        }
        for (int i = 1; i <= n; i++) {
            if (find(1) != find(i)) r = 1; //간선을 모두 연결한 후에도 1번 정점과 서로 다른 집합인 정점이 있는 경우 트리가 아니다.
        }
        printf("%s\n", r ? "graph" : "tree");
        for (int i = 1; i <= n; i++) g[i] = 0;
    }
    return 0;
}