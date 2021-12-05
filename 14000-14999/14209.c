#include <stdio.h>

/*
문제 : N(N <= 10000)개의 카드 13장 묶음이 주어질 때, 모든 카드의 점수 합을 구한다.
에이스는 4점, 킹은 3점, 퀸은 2점, 잭은 1점이다.

해결 방법 : N * 13장의 카드에 대해 각 카드의 점수를 확인하고 합을 구하면 된다.

주요 알고리즘 : 구현

출처 : COCI 16/17#4 1번
*/

int main(void) {
    int n, r = 0;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 13; j++) {
            scanf(" %c", &c);
            if (c == 'A') r += 4;
            else if (c == 'K') r += 3;
            else if (c == 'Q') r += 2;
            else if (c == 'J') r++;
            else if (c == 'X') continue;
            else return 1;
        }
    }
    printf("%d", r);
    return 0;
}