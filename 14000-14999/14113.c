#include <stdio.h>

/*
문제 : 크기가 5kg, 4kg, 3kg, 2kg, 1kg인 수박이 각각 A, B, C, D, E(A, B, C, D, E <= 1000)개 주어진다.
이때, 용량 5kg인 가방이 몇 개 필요한 지 구한다.

해결 방법 : 가장 크기가 큰 것부터 차례로 포장하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : CPC 2012 D번
*/

int main(void) {
    int a, b, c, d, e, r = 0, cap;
    scanf("%d %d %d %d %d", &e, &d, &c, &b, &a);
    while (a + b + c + d + e) {
        cap = 5;
        while (e > 0 && cap >= 5) {
            cap -= 5;
            e--;
        }
        while (d > 0 && cap >= 4) {
            cap -= 4;
            d--;
        }
        while (c > 0 && cap >= 3) {
            cap -= 3;
            c--;
        }
        while (b > 0 && cap >= 2) {
            cap -= 2;
            b--;
        }
        while (a > 0 && cap >= 1) {
            cap -= 1;
            a--;
        }
        r++;
    }
    printf("%d", r);
    return 0;
}