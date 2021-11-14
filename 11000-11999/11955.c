#include <stdio.h>

/*
문제 : R * S(R, S <= 100) 크기의 '.'과 '*'로 이루어진 배열이 주어질 때, K * K(3 <= K <= small(R, S)) 크기의 정사각형
범위 중 테두리를 제외한 부분의 '*'의 개수가 가장 많은 것의 개수를 구하고,
그 위치를 표시해서 출력한다.

해결 방법 : 모든 부분에 대해 K * K 크기 안을 확인한 다음, '*'의 개수를 확인하며 가장 많은 것의 개수와 위치를 저장한다.
가장 많은 것의 위치에서 원래 배열을 수정하여 위치를 표시한 다음 출력하면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : COCI 15/16#7 2번
*/

char wind[128][128];

int main(void) {
    int r, s, k, c, best = -1, bx = -1, by = -1;
    scanf("%d %d %d", &r, &s, &k);
    for (int i = 0; i < r; i++) {
        scanf("%s", &wind[i]);
    }
    for (int i = 0; i <= r - k; i++) {
        for (int j = 0; j <= s - k; j++) {
            c = 0;
            for (int ii = 1; ii < k - 1; ii++) {
                for (int jj = 1; jj < k - 1; jj++) {
                    if (wind[i + ii][j + jj] == '*') c++;
                }
            }
            if (c > best) {
                best = c;
                bx = i;
                by = j;
            }
        }
    }
    if (best < 0) return 1;

    for (int i = bx; i < bx + k; i++) {
        for (int j = by; j < by + k; j++) {
            if ((i == bx || i == bx + k - 1) && (j == by || j == by + k - 1)) wind[i][j] = '+';
            else if (i == bx || i == bx + k - 1) wind[i][j] = '-';
            else if (j == by || j == by + k - 1) wind[i][j] = '|';
        }
    }
    printf("%d\n", best);
    for (int i = 0; i < r; i++) {
        printf("%s\n", wind[i]);
    }
    return 0;
}