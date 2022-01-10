#include <stdio.h>

/*
문제 : N(N <= 50)장의 카드를 위에서부터 내림차순으로 쌓았다. R(R <= 50)번의 섞는 연산을 반복한 후,
맨 위에 있는 카드의 번호를 구한다. 섞을 때는 위에서부터 P번째 카드에서 시작하는 C장을 맨 위로
순서를 유지하며 올리는 행동을 한다.

해결 방법 : 문제의 설명대로 구현한 다음 맨 위의 카드 번호를 출력하면 된다.

주요 알고리즘 : 구현

출처 : JDC 2004 A번
*/

int card[64], mv[64];

int main(void) {
    int n, r, p, c;
    while (1) {
        scanf("%d %d", &n, &r);
        if (n == 0) break;
        for (int i = 0; i < n; i++) card[i] = n - i;
        for (int i = 0; i < r; i++) {
            scanf("%d %d", &p, &c);
            p--;
            for (int j = p; j < p + c; j++) mv[j - p] = card[j];
            for (int j = p + c - 1; j >= c; j--) card[j] = card[j - c];
            for (int j = 0; j < c; j++) card[j] = mv[j];
        }
        printf("%d\n", card[0]);
    }
    return 0;
}