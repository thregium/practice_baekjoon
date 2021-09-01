#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 20000)개의 지점들이 있다. 인접한 지점으로 이동하며 높이가 낮아지거나 같은 경우에는 비용이 들지 않지만
높이가 높아지는 곳으로 가는 경우에는 높이의 차만큼 비용이 든다고 할 때, K(K <= 20000)의 비용으로
가장 많은 지점을 갈 때의 갈 수 있는 지점 수를 구한다. 단, 아무 지점에서나 시작할 수 있다.

해결 방법 : 만약 한 지점에서 다른 지점을 갔다 오는 경우 비용은 갔다 온 지점에서 출발하는 경우의 비용과 같거나
더 많은 비용이 들게 된다. 따라서, 한 지점에서 한쪽 방향으로 지점하는 것이 최적의 방법이다.
한쪽 방향으로 이동하는 경우 갈 수 있는 최대 지점 수는 누적 합과 투 포인터 알고리즘을 통해 구할 수 있다.
왼쪽에서부터 이동할 때의 누적 비용과 오른쪽에서부터의 누적 비용을 미리 구해놓은 다음
포인터를 왼쪽과 오른쪽에서부터 움직이며 누적 비용의 차가 K 이하인 가장 넓은 구간을 구하면 된다.

주요 알고리즘 : 누적 합, 투 포인터

출처 : PA 2002.11 2-2번
*/

int h[20480];
long long lsum[20480], rsum[20480];

int main(void) {
    int n, k, s, e, r = 0;
    scanf("%d %d", &n, &k);
    h[0] = INF, h[n + 1] = INF;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
        if (h[i] > h[i - 1]) lsum[i] = lsum[i - 1] + h[i] - h[i - 1];
        else lsum[i] = lsum[i - 1];
    }
    for (int i = n; i > 0; i--) {
        if (h[i] > h[i + 1]) rsum[i] = rsum[i + 1] + h[i] - h[i + 1];
        else rsum[i] = rsum[i + 1];
    }
    lsum[n + 1] = INF, rsum[0] = INF;
    s = 1, e = 1;
    while (s <= n) {
        while (lsum[e] - lsum[s] <= k) {
            if (e - s + 1 > r) r = e - s + 1;
            e++;
        }
        s++;
    }
    s = n, e = n;
    while (e >= 1) {
        while (rsum[s] - rsum[e] <= k) {
            if (e - s + 1 > r) r = e - s + 1;
            s--;
        }
        e--;
    }
    printf("%d", r);
    return 0;
}