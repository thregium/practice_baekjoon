#include <stdio.h>

/*
문제 : C(C <= 10^9)를 10^K(0 <= K <= 9) 단위로 반올림한 수를 출력한다.

해결 방법 : 먼저 10^K(=M)의 값을 구한다. 만약 C % M의 값이 M / 2보다 작다면 버림을 하고, M / 2 이상인 경우
올림을 해주면 된다. 버림은 C - C % M으로 계산 가능하고, 올림은 버림한 값에 M을 더하면 된다.

주요 알고리즘 : 수학

출처 : COCI 09/10#3 2번
*/

int main(void) {
    int c, k, m = 1;
    scanf("%d %d", &c, &k);
    for (int i = 0; i < k; i++) m *= 10;
    if ((c % m) * 2 < m) printf("%d", c - c % m);
    else printf("%d", c - c % m + m);
    return 0;
}