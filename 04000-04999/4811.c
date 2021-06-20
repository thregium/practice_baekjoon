#include <stdio.h>

/*
문제 : N(N <= 30)개의 약을 하루에 반개씩 먹는다. 하루에 알약 하나를 꺼내서 알약이 한개짜리인 경우 알약을 반으로 나누어
반만 먹고 나머지 반은 통에 다시 넣어둔다. 반개짜리인 경우 그대로 먹는다. 각 알약이 구별 불가능하다면 알약 N개를 먹는 방법의 수를 구한다.

해결 방법 : 알약 한개를 꺼내는 것을 여는 괄호, 반개를 꺼내는 것을 닫는 괄호로 보면 괄호 문자열의 가짓수와 동치가 되고,
괄호 문자열은 카탈란 수로 풀 수 있으므로 카탈란 수를 이용하면 된다.

주요 알고리즘 : DP, 카탈란 수

출처 : Rocky 2011 E번
*/

long long mem[32];

int main(void) {
    mem[1] = 1;
    mem[2] = 2;
    for (int i = 3; i <= 30; i++) {
        mem[i] = mem[i - 1] * 2;
        for (int j = 1; j < i; j++) {
            mem[i] = (mem[i] + (long long)mem[j] * mem[i - j - 1]);
        }
    }
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%lld\n", mem[n]);
    }
    return 0;
}