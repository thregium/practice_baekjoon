#include <stdio.h>

/*
문제 : N(N <= 10^6) 이하의 자연수가 주어질 때,
어떤 자연수의 자릿수 합을 더해가며 N을 만드는 것이 가능한 자연수의 개수를 구한다.

해결 방법 : 모든 자연수에 대해 다음 수는 더 커지는 방향으로만 이동하므로 1부터 N까지 확인하면서
다음 수에 가능한 가짓수를 계산해 나가면 된다. 이때, 답이 N을 넘어가면 처리할 필요가 없다.

주요 알고리즘 : DP

출처 : JOI 2020예2 3번
*/

long long mem[1048576];

int main(void) {
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        mem[i] += 1;
        a = 0;
        for (int j = i; j; j /= 10) a += j % 10;
        if (a + i <= n) mem[a + i] += mem[i];
    }
    printf("%lld\n", mem[n]);
    return 0;
}