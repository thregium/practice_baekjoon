#include <stdio.h>

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 100000)개의 간선으로 이루어진 그래프를 연결된 트리 형태로 바꾸기 위해
간선을 잇거나 끊는 연산을 최소 몇 회 해야 하는지 구한다.

해결 방법 : 먼저 모든 정점들이 떨어진 상태에서는 N - 1회 잇는 연산을 해야 한다.
그리고 간선이 들어올 때 마다 유니온-파인드를 통해 같은 집합인지 확인한다.
같은 집합이 아닌 경우 잇는 연산의 횟수를 1회 줄일 수 있고, 같은 집합인 경우 끊는 연산이 1회 늘어나게 된다.
이를 계산하면서 결괏값을 구하면 된다.

주요 알고리즘 : 그래프 이론, 유니온 파인드

출처 : 강원대 1회 C번
*/

int g[103000];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, m, u, v, r;
    scanf("%d %d", &n, &m);
    r = n - 1;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        if (find(u) != find(v)) {
            uni(u, v);
            r--;
        }
        else r++;
    }
    printf("%d", r);
    return 0;
}