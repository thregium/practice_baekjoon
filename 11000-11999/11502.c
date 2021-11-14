#include <stdio.h>

/*
문제 : 자연수 K(7 <= K <= 1000)가 주어졌을 때, 세 소수를 더해서 이 수를 만드는 방법을 오름차순으로 출력한다.

해결 방법 : 미리 소수를 찾아둔 다음, 모든 경우를 확인해보면 된다.

주요 알고리즘 : 수학, 에라토스테네스, 브루트 포스

출처 : Daejeon 2015 J번
*/

char sieve[1024];

int main(void) {
    int t, k, r;
    for (int i = 2; i <= 1000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 1000; j += i) sieve[j] = 1;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &k);
        r = 0;
        for (int i = 2; i <= k; i++) {
            if (sieve[i]) continue;
            for (int j = i; j <= k - i - j; j++) {
                if (sieve[j] || sieve[k - i - j]) continue;
                printf("%d %d %d\n", i, j, k - i - j);
                r = 1;
                break;
            }
            if (r) break;
        }
        if (!r) return 1;
    }
    return 0;
}