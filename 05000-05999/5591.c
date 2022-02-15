#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100000)개의 절댓값이 10000 이하인 정수로 이루어진 배열의
연속된 K(K <= N)개의 원소 합 가운데 가장 큰 것을 구한다.

해결 방법 : 첫 K개 원소의 합을 구하고 그 이후로는 맨 뒤 다음 수를 더하고 맨 앞 수를 빼는 것을 반복하며
원소 합이 가장 큰 것을 구하면 된다.

주요 알고리즘 : 슬라이딩 윈도우

출처 : JOI 2007 1번
*/

int a[103000];

int main(void) {
    int n, k, s, r;
    for (int tt = 0; tt < 1; tt++) {
        scanf("%d %d", &n, &k);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        r = -INF, s = 0;
        for (int i = 0; i < k; i++) s += a[i];
        if (s > r) r = s;
        for (int i = k; i < n; i++) {
            s += a[i] - a[i - k];
            if (s > r) r = s;
        }
        printf("%d\n", r);
    }
    return 0;
}