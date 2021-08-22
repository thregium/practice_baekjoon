#include <stdio.h>

/*
문제 : N(N <= 10^6)일의 주가를 알고 있다고 할 때, 하루에 주식을 하나씩만 살 수 있고 수수료는 없다면
얻을 수 있는 가장 큰 수익을 구한다.

해결 방법 : 가장 주가가 높은 날을 알고 있다면 그 날 이전에는 계속 하나씩 주식을 사다가 가장 주가가 높은 날에 팔면 된다.
그 이후 날에는 그 이후 날들 중 가장 높은 날에 팔고, 이를 반복하여 이후 가장 높은 날을 계속 구하면 된다.
이를 빠르게 구하기 위해서는 최댓값을 역순으로 찾아 나간 다음, 최댓값에서 그 날의 주가와의 차이를 전부 더하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : Daejeon 2015 I번
*/

int price[1048576], best[1048576];

int main(void) {
    int t, n;
    long long r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &price[i]);
        }
        best[n] = 0;
        r = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (price[i] > best[i + 1]) best[i] = price[i];
            else best[i] = best[i + 1];
            r += best[i] - price[i];
        }
        printf("%lld\n", r);
    }
    return 0;
}