#include <stdio.h>

/*
문제 : N(N <= 300000)개의 정점으로 된 스패닝 트리에서 한 간선을 제거했을 때, 다시 스패닝 트리를 만들 수 있는
간선 가운데 하나를 출력한다.

해결 방법 : 나뉘어진 두 트리의 집합을 유니온 파인드로 구하고, 1번 정점에서 1번과 다른 집합으로 연결되는
간선을 찾아 출력하면 된다.

주요 알고리즘 : 그래프 이론, 자료 구조, 유니온 파인드, 트리

출처 : 선린 3회 D번
*/

int g[327680];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 2; i < n; i++) {
        scanf("%d %d", &a, &b);
        uni(a, b);
    }
    for (int i = 2; i <= n; i++) {
        if (find(1) != find(i)) {
            printf("%d %d", 1, i);
            return 0;
        }
    }
    return 1;
}