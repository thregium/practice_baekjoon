#include <stdio.h>

/*
문제 : 앞에서부터 몇 자리를 끊어도 소수가 되는 N(N <= 8)자리 수를 구한다.

해결 방법 : 가능한 수가 최대 1억이므로 1만까지의 모든 소수를 미리 구해준다. 그 뒤로는 첫 자리부터 백트래킹을 통해
N번째 자리까지 계속해서 모든 자리가 소수가 되는 수들을 구해주면 된다.

주요 알고리즘 : 수학, 소수 판정, 백트래킹
*/

int primes[2048], sieve[10240];
int pp = 0;

void track(int n, int c, int r) {
    if (n == c) {
        printf("%d\n", r);
        return;
    }
    int t;

    for (int i = 0; i < 10; i++) {
        if (c < 4) {
            if (sieve[r * 10 + i]) continue; //다음 자리로 i가 들어오면 소수가 아닌 경우
            track(n, c + 1, r * 10 + i);
        }
        else {
            t = 0;
            for (int j = 0; j < pp; j++) {
                if ((r * 10 + i) % primes[j] == 0) t++;
            }
            if (t) continue; //다음 자리로 i가 들어오면 소수가 아닌 경우
            track(n, c + 1, r * 10 + i);
        }
    }
}

int main(void) {
    int n;
    sieve[0] = 1;
    sieve[1] = 1;
    for (int i = 2; i <= 10000; i++) {
        if (sieve[i]) continue;
        primes[pp++] = i;
        for (int j = i * 2; j <= 10000; j += i) {
            sieve[j]++;
        }
    }
    scanf("%d", &n);
    track(n, 0, 0);
    return 0;
}