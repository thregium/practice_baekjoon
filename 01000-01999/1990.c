#include <stdio.h>

/*
문제 : 구간 [A, B](A, B <= 10^8)에서 팰린드롬이면서 소수인 수를 전부 구한다.

해결 방법 : 10^8 이하의 모든 팰린드롬 소수를 미리 구해놓고 시작한다. 에라토스테네스의 체를 통해 10000 이하의 모든 소수들을 구하고
10^8인 모든 팰린드롬에 대해 소수 여부를 구한다. 팰린드롬인 소수들을 전부 기록해놓으면 되는데, 10^8 이하의 팰린드롬의 수는
약 20000개 정도이고, 그 중 소수만 세면 그보다 훨씬 적을 것임을 알 수 있다. 또한, 10000 이하의 소수는 약 1000여개이므로
충분히 시간 내 풀 수 있는 양이다. 팰린드롬 소수를 전부 구한 다음에는 구간 내에 있는 팰린드롬 소수를 전부 출력하면 된다.

주요 알고리즘 : 
*/

int sieve[10240], primes[1280], palp[1024], b10[8] = {1, 10, 100, 1000, 10000, };
int pp = 0, lp = 0;

int rev(int n, int p) {
    int r = 0;
    if (p) n -= n % 10;
    while (n) {
        r *= 10;
        r += n % 10;
        n /= 10;
    }
    return r;
}

void track(int n) {
    int pal, com;
    for (int i = b10[((n + 1) >> 1) - 1]; i < b10[(n + 1) >> 1]; i++) {
        if (i == 1 && n == 1) continue;
        pal = i * b10[n >> 1] + rev(i, n & 1);
        com = 0;
        for (int i = 0; i < pp; i++) {
            if (pal == primes[i]) break;
            else if (pal % primes[i] == 0) {
                com = 1;
                break;
            }
        }
        if (com) continue;
        palp[lp++] = pal;
    }
}

int main(void) {
    for (int i = 2; i <= 10000; i++) {
        if (primes[i]) continue;
        primes[pp++] = i;
        for (int j = i * 2; j <= 10000; j += i) {
            primes[j] = 1;
        }
    }
    for (int i = 1; i < 9; i++) {
        track(i);
    }
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < lp; i++) {
        if (palp[i] < a) continue;
        if (palp[i] > b) break;
        printf("%d\n", palp[i]);
    }
    printf("-1");
    return 0;
}