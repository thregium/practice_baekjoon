#include <stdio.h>
#define INF 1012345678

/*
문제 : N!(N <= 10^6)을 B(B <= 1000)진법으로 나타내었을 때 맨 뒤에 붙는 0의 수를 T(T <= 1000)회 반복하여 구한다.

해결 방법 : 먼저 1000 이하의 모든 소인수들을 미리 구해준다. 그 다음, N과 B가 주어지면 N!의 B에 대한 소인수들의 수를 구한다.
이 수는 N을 f(B)(f(B)는 B의 소인수)로 계속 나누며 더한 N / f(B)의 값의 합과 같다. 이제 이 값들을 g(B)(g(B)는 f(B)의 개수)
로 나누어 준 값이 가장 작은 것이 답이 된다.

주요 알고리즘 : 수학, 정수론, 소수 판정

출처 : TUD 2006S 1번
*/

int sieve[1024], divi[1024][8], divic[1024][8], cnt[8];

int main(void) {
    int t, b, n, r;
    for (int i = 2; i <= 1000; i++) {
        if (sieve[i]) continue;
        for (int j = i; j <= 1000; j += i) {
            sieve[j] = 1;
            divi[j][++divi[j][0]] = i;
        }
    }
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j <= divi[i][0]; j++) {
            for (int x = i; !(x % divi[i][j]); x /= divi[i][j]) divic[i][j]++;
        }
    }

    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &b, &n);
        r = INF;
        for (int j = 1; j <= divi[b][0]; j++) {
            for (int x = n; x; x /= divi[b][j]) cnt[j] += x / divi[b][j];
        }
        for (int i = 1; i <= divi[b][0]; i++) {
            if (cnt[i] / divic[b][i] < r) r = cnt[i] / divic[b][i];
            cnt[i] = 0;
        }
        printf("Scenario #%d:\n", tt);
        printf("%d\n\n", r);
    }
    return 0;
}