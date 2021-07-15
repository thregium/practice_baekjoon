#include <stdio.h>
#define MOD 987654321

/*
문제 : N(N <= 10000, N은 짝수)명의 사람들이 원탁에 있을 때, 각 사람이 악수를 교차하지 않고 하는 방법의 가짓수를 구한다.

해결 방법 : 점화식은 카탈란 수가 된다. 따라서, 이에 맞게 카탈란 수를 구해주면 된다.

주요 알고리즘 : 수학, 다이나믹 프로그래밍
*/

int mem[5120];

int main(void) {
    mem[0] = 1;
    mem[1] = 2;
    for (int i = 2; i <= 5000; i++) {
        mem[i] = (mem[i - 1] * 2) % MOD;
        for (int j = 1; j < i; j++) {
            mem[i] = (mem[i] + (long long)mem[j - 1] * mem[i - j - 1]) % MOD;
        }
    }
    int n;
    scanf("%d", &n);
    printf("%d", mem[(n >> 1) - 1]);
    return 0;
}