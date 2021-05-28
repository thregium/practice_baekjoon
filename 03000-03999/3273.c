#include <stdio.h>

/*
문제 : N(N <= 100000)개의 수로 이루어진 수열이 있을 때, 서로 다른 위치의 두 수를 선택해서 합이 X(X <= 2 * 10^6)가 되는 쌍의 수를 구한다.
수열 내 수의 크기는 0 이상 10^6 이하이다.

해결 방법 : 수열 내 수의 크기가 작은 편이므로 각 수의 개수를 세서 쌍의 수를 구할 수 있다.
1 부터 100만까지 i값을 움직이며 x - i가 0 이상 i 이하일 동안 각 수의 쌍을 센다. 만약 두 수가 다르다면 두 수의 개수의 곱만큼이 쌍의 개수이고,
같다면 그 수의 개수 * (그 수의 개수 - 1) / 2가 쌍의 개수이다. 해당하는 값들을 전부 더하면 답이 된다.

주요 알고리즘 : 수학, 조합론, 카운팅

출처 : JBOI 2008 6번
*/

int cnt[1048576];

int main(void) {
    int n, a, x;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        cnt[a]++;
    }
    scanf("%d", &x);
    for (int i = 0; i <= 1000000; i++) {
        if (x - i > 1000000) continue;
        if (i > x - i) break;
        if (i * 2 == x) {
            r += ((long long)cnt[i] * (cnt[i] - 1)) >> 1;
        }
        else r += (long long)cnt[i] * cnt[x - i];
    }
    printf("%lld", r);
    return 0;
}