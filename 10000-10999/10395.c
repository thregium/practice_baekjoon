#include <stdio.h>

/*
문제 : 주어진 두 길이 5인 비트 쌍의 모든 비트가 서로에 대해 반전된 상태인지 구한다.

해결 방법 : 5개 모든 비트에 대해 서로 XOR한 결과가 1인 경우 조건을 만족하고, 그렇지 않은 경우 조건을 만족하지 않는다.

주요 알고리즘 : 구현

출처 : Latin 2014 A번
*/

int main(void) {
    int x1, x2, x3, x4, x5, y1, y2, y3, y4, y5;
    scanf("%d %d %d %d %d%d %d %d %d %d", &x1, &x2, &x3, &x4, &x5, &y1, &y2, &y3, &y4, &y5);
    if ((x1 ^ y1) & (x2 ^ y2) & (x3 ^ y3) & (x4 ^ y4) & (x5 ^ y5)) printf("Y");
    else printf("N");
    return 0;
}