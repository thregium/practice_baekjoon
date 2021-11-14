#include <stdio.h>

/*
문제 : 1개의 모음과 1개의 자음으로 만들 수 있는 L(L <= 15) 길이의 문자열 가짓수룰 구한다.
단, 자음 뒤에는 반드시 모음이 와야 한다.

해결 방법 : 끝 자리가 자음일 때와 모음일 때로 나누어 다이나믹 프로그래밍을 진행한다.
:L번째 문자열 가운데 끝 자리가 모음일 때의 가짓수가 답이 된다.

주요 알고리즘 : 구현, DP

출처 : GCJ 2016W C1번
*/

int mem[16][2];

int main(void) {
    int t, c, v, l;
    mem[0][0] = 1;
    for (int i = 1; i <= 15; i++) {
        mem[i][0] = mem[i - 1][0] + mem[i - 1][1];
        mem[i][1] = mem[i - 1][0];
    }
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d", &c, &v, &l);
        printf("Case #%d: %d\n", tt, mem[l][0]);
    }
    return 0;
}