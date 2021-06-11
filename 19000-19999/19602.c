#include <stdio.h>

/*
문제 : S + M * 2 + L * 3의 값이 행복도라고 할 때, 행복도가 10 이상이면 happy, 미만이면 sad를 출력한다.

해결 방법 : 문제에 쓰여있는대로 구현한다.

주요 알고리즘 : 수학, 사칙연산

출처 : CCC 2020 J1번
*/

int main(void) {
    int s, m, l;
    scanf("%d%d%d", &s, &m, &l);
    if (s + m * 2 + l * 3 >= 10) printf("happy");
    else printf("sad");
    return 0;
}