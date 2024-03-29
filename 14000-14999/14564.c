#include <stdio.h>

/*
문제 : N(N <= 100000)명이 M(M <= 10000)모로 두부 게임을 한다. 이때, 주최자가 되는 사람의 번호를 게임이 끝날 때 까지 출력한다.
게임은 10000번 내로 끝난다.

해결 방법 : 주최자의 모 수를 기준으로 더 큰 경우와 더 작은 경우로 나눈다. 해당 모 수인 사람의 번호를 덧셈과 나머지 연산을
이용해 구한 다음, 그 사람으로 주최자를 바꾸어 반복하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 수학

출처 : 중앙대 2017R D번
*/

int main(void) {
    int n, m, a, x;
    scanf("%d %d %d", &n, &m, &a);
    while (1) {
        scanf("%d", &x);
        if (x == (m >> 1) + 1) {
            printf("0");
            break;
        }
        else if (x > (m >> 1) + 1) {
            a += x - (m >> 1) - 2;
            a %= n;
            a++;
        }
        else {
            a -= (m >> 1) - x + 2;
            a %= n;
            if (a < 0) a += n;
            a++;
        }
        printf("%d\n", a);
    }
    return 0;
}