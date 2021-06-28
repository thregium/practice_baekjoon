#include <stdio.h>

/*
문제 : 5000원으로 여러 음료수들을 살 때, 거스름돈을 구한다. 단, 5000원 넘게 사는 경우는 없다.

해결 방법 : 모든 음료수에 대해 반복하며 음료수의 종류에 따라 남은 돈을 계산하면 된다.

주요 알고리즘 : 구현

출처 : 경찰대 2019 B번
*/

int main(void) {
    int n, r = 5000;
    while (scanf("%d", &n) != EOF) {
        if (n == 1) r -= 500;
        else if (n == 2) r -= 800;
        else r -= 1000;
    }
    printf("%d", r);
    return 0;
}