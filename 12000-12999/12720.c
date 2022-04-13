#include <stdio.h>

/*
문제 : [A, B](1 <= A <= B <= 10^12, B - A <= 10^6) 구간에서 P(P <= B) 이상의 소인수를 갖는
수들을 각각 하나의 그룹으로 묶을 때, [A, B]의 수들은 몇 개의 그룹이 되는 지 구한다.

해결 방법 : 에라토스테네스의 체를 이용해 10^6 이하의 소수들을 전처리해준다.
그 다음, P 이상 B - A 이하의 소수들에 대해 그룹들을 합쳐준다. 이는 유니온-파인드를 통해
빠르게 합쳐야 한다. 확인하는 시작점은 ceil(A / X) + X이고, 끝점은 B이며,
이 그룹들을 ceil(A / X)의 그룹과 합치면 된다. 그 후, 그룹의 수를 세서 답을 출력한다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스, 유니온-파인드

출처 : GCJ 2008B B2번
*/

char sieve[1048576];
int prime[103000], g[1048576];
int pp = 0;

int find(int x) {
    if (g[x] < 0) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int t, p;
    long long a, b, stt, res;
    for (int i = 2; i <= 1000001; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 1000001; j += i) sieve[j] = 1;
    }

    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%lld %lld %d", &a, &b, &p);
        for (long long i = 0; i <= b - a; i++) g[i] = -1;

        res = b - a + 1;
        for (int i = 0; i < pp; i++) {
            if (prime[i] > b - a) break;
            else if (prime[i] < p) continue;
            stt = a / prime[i] * prime[i];
            if (stt < a) stt += prime[i];
            for (long long j = stt + prime[i]; j <= b; j += prime[i]) {
                if (find(stt - a) != find(j - a)) {
                    res--;
                    uni(stt - a, j - a);
                }
            }
        }
        printf("Case #%d: %lld\n", tt, res);

    }
    return 0;
}