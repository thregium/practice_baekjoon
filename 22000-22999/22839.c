#include <stdio.h>

/*
문제 : 1부터 289까지의 제곱수로 이루어진 단위의 동전들이 있을 때, N(N <= 300)을 만드는 방법의 가짓수를 구한다.

해결 방법 : 다이나믹 프로그래밍을 통해 풀면 된다.

주요 알고리즘 : DP, 냅색

출처 : Kyoto 1999 B번
*/

int mem[384];

int main(void) {
    int n;
    mem[0] = 1;
    for (int i = 1; i <= 17; i++) {
        for (int j = i * i; j <= 300; j++) {
            mem[j] += mem[j - i * i];
        }
    }
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d\n", mem[n]);
    }
    return 0;
}