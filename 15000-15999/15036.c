#include <stdio.h>

/*
문제 : N(N <= 2000)개의 음표 종류가 주어질 때, 전체 음표의 길이를 구한다.

해결 방법 : 각 음표의 길이를 확인하고 합을 구한 후 출력하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : UKIEPC 2017 J번
*/

int main(void) {
    int n, x;
    double r = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        switch (x) {
        case 0:
            r += 1.0;
        case 1:
            r += 0.5;
        case 2:
            r += 0.25;
        case 4:
            r += 0.125;
        case 8:
            r += 0.0625;
        case 16:
            r += 0.0625;
            break;
        default:
            return 1;
        }
    }
    printf("%.9f", r);
    return 0;
}