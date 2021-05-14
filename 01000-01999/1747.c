#include <stdio.h>

/*
문제 : N(N <= 10^6)보다 크거나 같은 가장 작은 팰린드롬 소수를 구한다.

해결 방법 : 10^6 이하의 모든 팰린드롬 소수를 미리 구해놓고 시작한다. 에라토스테네스의 체를 통해 1000 이하의 모든 소수들을 구하고
10^6인 모든 팰린드롬에 대해 소수 여부를 구한다. 팰린드롬인 소수들을 전부 기록해놓으면 되는데, 10^6 이하의 팰린드롬의 수는
약 2000개 정도이고, 그 중 소수만 세면 그보다 훨씬 적을 것임을 알 수 있다. 또한, 1000 이하의 소수는 약 200여개이므로
충분히 시간 내 풀 수 있는 양이다. 이 수들을 하나씩 확인해가다 N보다 크거나 같은 수를 만나면 그 수를 출력하고 빠져나가면 된다.

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
    int n;
    scanf("%d", &n);
    for (int i = 0; i < lp; i++) {
        if (palp[i] >= n) {
            printf("%d", palp[i]);
            break;
        }
    }
    return 0;
}