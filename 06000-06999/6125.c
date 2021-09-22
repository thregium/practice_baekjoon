#include <stdio.h>

/*
문제 : P(P <= 5000)개의 정점으로 이루어진 이진 트리에서 1번 정점부터 T번 정점까지 가는 경로를 구한다.
반드시 1번 정점이 루트로 주어진다.

해결 방법 : 1번 정점이 반드시 루트이기 때문에 T번 정점에서 부모 정점을 계속 따라가다 보면 반드시 1번 정점을 만나게 된다.
따라서, 각 정점의 부모 정점을 저장한 다음, T번 정점부터 부모 정점을 따라 1번 정점에 도달하는 경로를 저장한 후,
역순으로 출력하면 된다.

주요 알고리즘 : 그래프 이론, 트리

출처 : USACO 2009O B4번
*/

int par[5120], path[5120];

int main(void) {
    int p, ns, t, n, b1, b2, res = 0;
    scanf("%d %d %d", &p, &ns, &t);
    for (int i = 0; i < ns; i++) {
        scanf("%d %d %d", &n, &b1, &b2);
        if (par[b1] || par[b2]) return 1;
        par[b1] = n;
        par[b2] = n;
    }
    while (t) {
        path[res++] = t;
        t = par[t];
    }
    printf("%d\n", res);
    for (int i = res - 1; i >= 0; i--) {
        printf("%d\n", path[i]);
    }
    return 0;
}