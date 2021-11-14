#include <stdio.h>

/*
문제 : 한번에 5kg씩 담을 수 있는 바구니가 있을 때, 1kg, 2kg, 3kg, 4kg, 5kg인 물건의 개수(<= 1000)가 각각 주어지면,
모든 물건을 담기 위해 바구니가 최소 몇 개 필요한지 구한다.

해결 방법 : 무거운 물건부터 차례로 담아본다. 5kg인 물건은 그 물건 하나만 담을 수 있고, 4kg은 1kg짜리와 함께,
3kg은 2kg 또는 1kg 2개와 함께, 2kg은 2kg + 1kg 또는 2kg + 1kg * 3으로 담을 수 있는데,
모두 이러한 전략에 부합하므로 이러한 전략으로 물건을 담고 바구니의 수를 구하면 된다.

주요 알고리즘 : 그리디 알고리즘
*/

int main(void) {
    int a, b, c, d, e, r = 0, cap;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
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