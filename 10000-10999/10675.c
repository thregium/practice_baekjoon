#include <stdio.h>
#define INF 1012345678

/*
문제 : 주어진 N(N <= 100)개의 루트 중 A에서 B로 갈 수 있는 가장 가격이 싼 루트를 찾는다.
각 루트에서는 각 지점들을 방문하며, 한번 방문했던 지역은 방문하지 않는다.

해결 방법 : 각 루트에서 한번 방문했던 지점은 다시 방문하지 않기 때문에 A를 방문한 후 B를 방문한 루트에 대해
가장 싼 루트를 찾으면 된다.

주요 알고리즘 : 구현

출처 : USACO 2015J B1번
*/

int main(void) {
    int a, b, n, best = INF, c, cn, x, fa, fb;
    scanf("%d %d %d", &a, &b, &n);
    if (a == b) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &cn);
        fa = 0, fb = 0;
        for (int j = 0; j < cn; j++) {
            scanf("%d", &x);
            if (x == a) fa = 1;
            if (x == b && fa) fb = 1;
        }
        if (fb && c < best) best = c;
    }
    if (best == INF) printf("-1");
    else printf("%d", best);
    return 0;
}