#include <stdio.h>

/*
문제 : N(N <= 10^6)명의 신하가 있는 왕국이 있다. 총리 이하로 각 신하의 상관 번호가 주어질 때,
처형될 수 있는 사람의 최대 수를 구한다. 각 신하는 부하 가운데 최대 1명을 처형할 수 있다.

해결 방법 : 트리의 아래 정점부터 차례로 처형될 사람을 뽑는다. 살아남는 사람은 그의 직속 상관 가운데
살아남는 것이 확정되지 않는 가장 하위의 사람이다. 살아남을 사람이 없는 경우 처형되지 않는다.
이를 반복하여 처형한 횟수가 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 트리, 유니온 파인드

출처 : JPOI 2011 1-3번
*/

int p[1048576], uf_g[1048576], saved[1048576];

int uf_find(int x) {
    if (uf_g[x] < 0) return x;
    else return uf_g[x] = uf_find(uf_g[x]);
}

void uf_uni(int x, int y) {
    if (uf_find(x) == uf_find(y)) return;
    uf_g[uf_find(y)] = uf_find(x);
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p[i]);
        uf_g[i] = -1;
    }
    uf_g[1] = -1;
    uf_g[0] = -1;
    for (int i = n; i > 1; i--) {
        if (saved[i]) continue;
        if (uf_find(p[i]) >= 1) {
            saved[uf_find(p[i])] = 1;
            uf_uni(p[uf_find(p[i])], uf_find(p[i]));
            r++;
        }
    }
    printf("%d", r);
    return 0;
}