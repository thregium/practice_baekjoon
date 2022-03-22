#include <stdio.h>

/*
문제 : P(P <= 211) 이하의 소수가 주어진다. 이때, 2부터 소수들을 거쳐서 P까지 가되,
중간에 14보다 많이 건너뛰지 않도록 가는 방법의 가짓수를 구한다.

해결 방법 : 각 소수들을 체를 통해 전처리한 후 각 소수마다 최근 방문한 소수가 얼마 전인지에 따라
방법의 가짓수를 다이나믹 프로그래밍을 통해 구한다. 최근 소수의 위치에서 떨어진 거리에 따라
현재 소수를 선택하는 경우, 아닌 경우를 나누면 된다.
답은 P에서 최근 방문한 소수와의 거리가 0일 때의 가짓수이다.

주요 알고리즘 : DP, 소수 판정

출처 : CTU 2021 A번
*/

char sieve[256];
long long mem[256][16];

int main(void) {
    int p, last = 2;
    scanf("%d", &p);
    for (int i = 2; i <= p; i++) {
        for (int j = i * 2; j <= p; j += i) sieve[j] = 1;
    }
    mem[2][0] = 1;
    for (int i = 3; i <= p; i++) {
        if (sieve[i]) continue;
        for (int j = i - last; j <= 14; j++) {
            mem[i][j] += mem[last][j - (i - last)];
            mem[i][0] += mem[last][14 - j];
        }
        last = i;
    }
    printf("%lld", mem[p][0]);
    return 0;
}
