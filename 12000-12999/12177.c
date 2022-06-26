#include <stdio.h>
#include <stdlib.h>

/*
문제 : K(K <= 10^9)개의 세 채널의 색상 수준(0 ~ K, 자연수) 가운데 고른 세 채널의 색상 수준 차이가
V(V <= 1000) 이하가 되는 경우의 수를 구한다.

해결 방법 : 각 V개 연속된 색상마다 그 가운데 하나를 고르는 작업을 하여 그 합을 구하고,
다시 V - 1개 연속된 색상(양 끝 제외)마다 그 가운데 하나를 고르는 작업을 하여 그 합을 빼내면 답이 된다.

주요 알고리즘 : 수학, 조합론, 포함배제

출처 : GCJW 2015 B3번
*/

int main(void) {
    int t, k, v;
    long long res;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &k, &v);
        res = 0;
        for (int i = v; i >= 2 * v - k - 1 && i >= v - 1; i--) {
            if ((v - i) & 1) res -= (i + 1LL) * (i + 1LL) * (i + 1LL) * (k - v - (v - i) + 1LL);
            else res += (i + 1LL) * (i + 1LL) * (i + 1LL) * (k - v - (v - i) + 1LL);
        }
        printf("Case #%d: %lld\n", tt, res);
        /*
        res = 0;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                for (int kk = 0; kk <= k; kk++) {
                    if (abs(i - j) <= v && abs(i - kk) <= v && abs(j - kk) <= v) res++;
                }
            }
        }
        printf("%lld\n", res);
        */
    }
    return 0;
}