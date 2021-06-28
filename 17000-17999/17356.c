#include <stdio.h>
#include <math.h>

/*
문제 : 두 사람의 ELO레이팅이 주어질 때, 승률을 주어진 공식을 이용해 계산한다.(공식 생략)

해결 방법 : 공식을 식으로 옮겨서 구한 후 출력하면 된다.

주요 알고리즘 : 수학, 구현

출처 : 선린 3회 H번
*/

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    double m = (b - a) / 400.0;
    printf("%f", 1 / (1 + pow(10, m)));
    return 0;
}