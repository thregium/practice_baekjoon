#include <stdio.h>

/*
문제 : N(N <= 100000)개의 K(K <= 100000) 이하 자연수로 이루어진 배열이 주어질 때,
이 배열에서 어떠한 인접한 두 수도 같지 않은 가장 긴 구간을 구한다.

해결 방법 : 앞 수와 다른 것이 나올 때 마다 카운터를 초기화시키면서 카운터의 최댓값을 구하면 된다.

주요 알고리즘 : 구현

출처 : ROI 2018T I번
*/

int a[103000];

int main(void) {
    int n, k, res = 0, cnt = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i == 0 || a[i - 1] != a[i]) cnt++;
        else cnt = 1;
        if (cnt > res) res = cnt;
    }
    printf("%d", res);
    return 0;
}