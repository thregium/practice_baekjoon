#include <stdio.h>

/*
문제 : N(N <= 50000)개의 지점이 원형으로 놓여있다. 원주상에서 각 인접 지점 사이의 거리가 주어질 때,
원주상에서 두 지점 사이 거리가 가장 먼 것을 구한다.

해결 방법 : 누적 합을 관리하면서 앞쪽 구간이 뒤쪽 구간과 최대한 비슷해지는 지점을 유지해 나가도록
시작과 끝점을 관리한다. 그 가운데 양쪽 가운데 작은 쪽의 값이 최대가 되는 경우를 찾으면 된다.

주요 알고리즘 : 누적 합, 투 포인터
*/

int dist[51200];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, sum = 0, last = 0, tsum = 0, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &dist[i]);
        sum += dist[i];
    }
    for (int i = 0; i < n; i++) {
        while (tsum < sum - tsum) {
            if (small(tsum, sum - tsum) > res) res = small(tsum, sum - tsum);
            tsum += dist[last];
            last = (last + 1) % n;
        }
        if (small(tsum, sum - tsum) > res) res = small(tsum, sum - tsum);
        tsum -= dist[i];
    }
    printf("%d", res);
    return 0;
}