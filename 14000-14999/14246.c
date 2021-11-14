#include <stdio.h>

/*
문제 : 길이 N(N <= 100000)의 자연수(<= 100000)로 이루어진 수열이 주어진다. 이때, 이 수열에서 범위 [i, j]에 대해
합이 K(K <= 100000)가 되는 범위의 개수를 구한다.

해결 방법 : 투 포인터 알고리즘을 이용해 구간의 합이 K보다 커질 때 마다 해당 범위의 끝 이후의 개수를 더해나간다.
이를 끝점이 배열을 벗어날 때 까지 하면 된다.

주요 알고리즘 : 투 포인터
*/

int a[103000];

int main(void) {
    int n, k, st = 0, ed = 0;
    long long r = 0, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    while (ed < n || sum > k) {
        if (sum <= k) {
            sum += a[ed++];
        }
        else {
            r += n - ed + 1;
            sum -= a[st++];
        }
    }
    printf("%lld", r);
    return 0;
}