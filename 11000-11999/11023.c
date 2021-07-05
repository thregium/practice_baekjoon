#include <stdio.h>

/*
문제 : 임의의 개수만큼 수들을 더한 결과를 구한다.

해결 방법 : EOF를 이용한다.

주요 알고리즘 : 구현?
*/

int main(void) {
    int sum = 0, x;
    while (scanf("%d", &x) != EOF) sum += x;
    printf("%d", sum);
    return 0;
}