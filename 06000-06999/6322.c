#include <stdio.h>
#include <math.h>

/*
문제 : 직각삼각형의 세 변 중 하나의 길이를 모를 때, 직각삼각형을 만들 수 있는지 구하고, 가능하다면 그 변의 길이룰 구한다.

해결 방법 : 우선, 빗변의 길이를 모르는 경우에는 항상 직각삼각형을 만들 수 있고, 그때의 길이는 피타고라스 정리에 따라
다른 두변의 길이의 제곱의 합의 제곱근과 같다. 나머지 변을 모르는 경우에는 빗변이 아는 다른 한 변보다 길다면 만들 수 있고,
빗변의 제곱 - 남은 한 변의 제곱의 제곱근과 같다. 이하가 되는 경우 해당 변의 길이가 0 이하가 되어버리므로 불가능하다.

주요 알고리즘 : 기하학, 피타고라스 정리

출처 : SWERC 1997 PB번
*/

int main(void) {
    int a, b, c;
    for (int tt = 1;; tt++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0) break;
        printf("Triangle #%d\n", tt);
        if (a == -1) {
            if (b >= c) printf("Impossible.");
            else printf("a = %.3f", sqrt(c * c - b * b));
        }
        else if (b == -1) {
            if (a >= c) printf("Impossible.");
            else printf("b = %.3f", sqrt(c * c - a * a));
        }
        else {
            printf("c = %.3f", sqrt(a * a + b * b));
        }
        printf("\n\n");
    }
    return 0;
}