#include <stdio.h>

/*
문제 : 각 과제의 점수에 맞게 등급을 분류한다.

해결 방법 : 분류대로 등급을 나누면 된다.

주요 알고리즘 : 구현

출처 : SwOI 2019OQ A번
*/

int main(void) {
    int a, b, c, x, y, z;
    scanf("%d %d %d%d %d %d", &a, &b, &c, &x, &y, &z);
    if (y * 2 < b) printf("E");
    else if (y < b) printf("D");
    else if (x * 2 < a) printf("C");
    else if (x < a) printf("B");
    else printf("A");
    return 0;
}