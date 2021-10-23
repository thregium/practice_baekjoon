#include <stdio.h>

/*
문제 : N(N <= 32)개의 비트로 이루어진 배열 가운데 1이 L(L <= N)개 이하인 사전순으로 I번째 배열을 구한다.
I번째 배열은 반드시 존재하도록 주어진다.

해결 방법 : L개 이하의 비트가 1인 길이 N의 배열을 다이나믹 프로그래밍을 통해 미리 구해준다.
그 다음, 길이 N - 1의 비트 1인 배열의 개수와 I를 비교해 나가며 수를 앞 자리부터 차례로 확인해 나간다.
I가 그 이하인 경우 앞 자리는 0이고, 그보다 크다면 앞 자리는 1이다. 앞 자리가 1이라면 L을 1 줄이고,
I를 해당하는 개수만큼 줄인다. 그 다음, 어떤 경우든 N을 1씩 줄인다.

주요 알고리즘 : DP, 조합론
*/

long long mem[32][32];

int main(void) {
    for (int i = 0; i < 32; i++) {
        mem[0][i] = 1;
    }
    for (int i = 1; i < 32; i++) {
        mem[i][0] = 1;
        for (int j = 1; j < 32; j++) {
            mem[i][j] = mem[i - 1][j - 1] + mem[i - 1][j];
        }
    }
    long long n, l, ib;
    scanf("%lld %lld %lld", &n, &l, &ib);
    if (ib > mem[n][l]) return 1;
    while (n-- > 0) {
        if (mem[n][l] >= ib) {
            printf("0");
        }
        else {
            printf("1");
            ib -= mem[n][l];
            l--;
        }
    }
    return 0;
}