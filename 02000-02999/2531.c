#include <stdio.h>

/*
문제 : N(N <= 30000)개의 원형으로 이루어진 배열에서 값이 (1 <= Ai <= D <= 3000)인 자연수로 주어질 때,
연속한 K(K <= 3000)개의 원소로 이루어진 집합에 원소 C를 더한 집합의 원소의 가짓수를 구한다.

해결 방법 : N * K가 크지 않으므로 모든 경우에 대해 검사해보면 된다.

주요 알고리즘 : 브루트 포스

출처 : 정올 2012지 중2번
*/

int a[32768], cnt[4096];

int main(void) {
    int n, d, k, c, t, r = 0;
    scanf("%d %d %d %d", &n, &d, &k, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cnt[a[(i + j) % n]]++;
        }
        cnt[c]++;
        t = 0;
        for (int j = 1; j <= d; j++) {
            if (cnt[j]) {
                cnt[j] = 0;
                t++;
            }
        }
        if (t > r) r = t;
    }
    printf("%d", r);
    return 0;
}