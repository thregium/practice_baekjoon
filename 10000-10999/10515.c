#include <stdio.h>

/*
문제 : D(D <= 10000)의 거리를 K(K <= 10000)만큼의 연료통으로 가려고 한다. 중간에 S(S <= 100)개의 주유소 위치들이
오름차순으로 주어진다. 이때, 주유소를 최소한으로 들른다면 들러야 하는 주유소들을 출력한다.
갈 수 없는 경우에는 out of petrol을 출력한다. 출발시에는 연료가 가득 찬 상태이다.

해결 방법 : 현재 연료로 다음 주유소(또는 목적지)에 갈 수 없을 때 마다 이번 주유소에 들른다. 만약 이번 주유소에서 주유하더라도
다음 주유소로 갈 수 없다면 out of petrol을 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : Lahore 2014O 2번
*/

int fuel[128], res[128];

int main(void) {
    int t, d, k, n, f, r = 1, rn;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d", &d, &k, &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &fuel[i]);
        }
        fuel[n + 1] = d;
        f = k;
        rn = 0;
        r = 1;
        for (int i = 0; i <= n; i++) {
            if (fuel[i + 1] - fuel[i] > k) {
                r = 0;
                break;
            }
            else if (fuel[i + 1] - fuel[i] > f) {
                f = k;
                res[rn++] = fuel[i];
            }
            f -= fuel[i + 1] - fuel[i];
        }

        printf("Case #%d: ", tt);
        if (r == 0) printf("out of petrol\n");
        else {
            for (int i = 0; i < rn; i++) {
                printf("%d ", res[i]);
            }
            printf("\n");
        }
    }
    return 0;
}