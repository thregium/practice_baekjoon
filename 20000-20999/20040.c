#include <stdio.h>

/*
문제 : N(N <= 500000)개의 정점으로 이루어진 그래프에 M(M <= 10^6)개의 간선을 그었다.
이때, 그래프에서 최초로 사이클이 생기는 시점을 구한다. 끝까지 사이클이 생기지 않는다면 0을 출력한다.

해결 방법 : 분리 집합을 이용한다. 각 간선을 긋기 전에 두 집합이 같은 집합인지 확인하고 같은 집합이면
그때의 번호를 출력한 다음 프로그램을 종료한다. 다른 집합인 경우 두 집합을 합치고 다음 간선을 확인한다.
끝까지 확인했다면 사이클이 없는 것이므로 0을 출력한다.

주요 알고리즘 : 자료 구조, 유니온 파인드

출처 : Seoul 2020I E번
*/

int g[524288];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        a++, b++;
        if (find(a) == find(b)) {
            printf("%d", i);
            return 0;
        }
        else uni(a, b);
    }
    printf("0");
    return 0;
}