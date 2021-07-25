#include <stdio.h>

/*
문제 : 1 / 2 + 1 / 3 + ... + 1 / (n + 1)이 S(S <= 5.2) 이상이 되는 가장 작은 N을 구한다.

해결 방법 : 1 / 2부터 차례로 더해가다 S 이상이 되는 값이 나오는 가장 작은 값을 출력하면 된다.

주요 알고리즘 : 수학

출처 : MidC 2001 E번
*/

int main(void) {
    double s, x;
    int i;
    while (1) {
        scanf("%lf", &s);
        if (s < 0.001) break;
        x = 0.0;
        for (i = 1; x < s; i++) {
            x += 1.0 / (i + 1.0);
        }
        printf("%d card(s)\n", i - 1);
    }
    return 0;
}