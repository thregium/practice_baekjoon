#include <stdio.h>

/*
문제 : 주어진 3-SAT 문제를 푼 결과를 출력한다(?)

해결 방법 : 는 거짓말이고 자세히 보면 사실 M의 크기가 8 이상이면 참, 8 미만이면 거짓을 출력한다고 나온다.

주요 알고리즘 : 구현?

출처 : Bergen 2018 C번
*/

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    if (m >= 8) printf("satisfactory");
    else printf("unsatisfactory");
    return 0;
}