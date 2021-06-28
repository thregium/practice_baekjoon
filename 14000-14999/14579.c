#include <stdio.h>

/*
문제 : 1부터 A까지의 누적합부터 1부터 B(A < B <= 1000)까지의 누적합까지의 누적곱을 구한다.

해결 방법 : 직접 누적합을 구해준 다음 곱하는 것을 반복하면 된다.

주요 알고리즘 : 수학, 구현

출처 : 연세대 2017 PB번
*/

int main(void) {
    int a, b, r = 1, t = 0;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        t = 0;
        for (int j = 1; j <= i; j++) {
            t += j;
        }
        t %= 14579;
        r = r * t % 14579;
    }
    printf("%d", r);
    return 0;
}