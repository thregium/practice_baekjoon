#include <stdio.h>

/*
문제 : 1일동안 A만큼 올라가고 B(B < A <= 100)만큼 내려가는 벌레가 바닥에서 H(H <= 100000)만큼 올라오는 데
얼마나 걸리는 지 구한다.

해결 방법 : 매일 A - B만큼 올라가고 처음에 H - A만큼의 거리가 있으므로 그 값을 올림한 만큼 + 1이 답이 된다.
단, A가 H보다 큰 경우 음수가 되지 않도록 유의한다.

주요 알고리즘 : 수학

출처 : VTH 2018 A번
*/

int main(void) {
    int a, b, h;
    scanf("%d %d %d", &a, &b, &h);
    if (a > h) printf("1");
    else printf("%d", (h - b - 1) / (a - b) + 1);
    return 0;
}