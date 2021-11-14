#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 10^9)명에게 M(M <= 300000, N)가지 색상의 보석을 나누어 주려고 한다. 한 사람에게 한 가지 색상의 보석만
나누어 줄 수 있다면, 보석을 가장 많이 갖는 사람은 최소 몇 개를 갖게 되는지 구한다.

해결 방법 : 각 사람에게 나누어주는 보석의 최대 개수를 제한으로 두고 매개 변수 탐색을 진행해 나가면 된다.

주요 알고리즘 : 파라메트릭

출처 : COCI 12/13#1 4번
*/

int gem[327680];

long long getres(int m, int x) {
    long long r = 0;
    for (int i = 0; i < m; i++) {
        r += (gem[i] + x - 1) / x;
    }
    return r;
}

int main(void) {
    int n, m, lo = 1, hi = INF, mid;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &gem[i]);
    }
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (getres(m, mid) <= n) hi = mid;
        else lo = mid + 1;
    }
    printf("%d", lo);
    return 0;
}