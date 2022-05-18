#include <stdio.h>

/*
문제 : 자연수 N(N <= 30)을 K로 나눈 나머지가 M인 자연수를 쓰지 않고 자연수로 분할하는
방법의 가짓수를 구한다. 순서만 다른 것도 다른 것으로 친다.

해결 방법 : 각 수에 대해 해당 수의 가짓수를 저장한다. 1부터 N까지 올라가며, M + K의 배수를 제외한
현재 수 이하의 수만큼 전의 가짓수를 현재 수의 가짓수에 더해가는 것을 반복한 다음,
N일 때의 답을 구하면 된다.

주요 알고리즘 : DP

출처 : GNY 2015 G번 // IIPC 2015 G번
*/

int mem[32];

int main(void) {
    int t, d, n, m, k;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d %d", &d, &n, &m, &k);
        mem[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (j % k == m) continue;
                mem[i] += mem[i - j];
            }
        }
        printf("%d %d\n", d, mem[n]);

        for (int i = 0; i < 32; i++) mem[i] = 0;
    }
    return 0;
}