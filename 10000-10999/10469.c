#include <stdio.h>

/*
문제 : 8 * 8 크기 체스판에서 퀸들이 놓인 위치가 주어질 때, 이것이 8-Queen 문제의 답 중 하나인지 구한다.

해결 방법 : 체스판에서 각 퀸들에 대해 다시 체스판의 각 칸을 사리며 다른 퀸이 간섭받는 위치에 있는지 확인한다.
그러한 경우가 있다면 8-Queen 문제의 답이 될 수 없다. 그러한 경우가 없다면 퀸이 8개인지 확인하고,
8개가 맞다면 8-Queen 문제의 해답이라고 할 수 있다.

주요 알고리즘 : 구현

출처 : NAQ 2014 A / 2020 C번
*/

char qn[16][16];

int main(void) {
    int r = 1, c = 0;
    for (int i = 0; i < 8; i++) {
        scanf("%s", qn[i]);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (qn[i][j] != '*') continue;
            c++;
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (i == k && j == l) continue;
                    if (qn[k][l] != '*') continue;
                    if (i == k || j == l || i + j == k + l || i - j == k - l) r = 0;
                }
            }
        }
    }
    if (c != 8) r = 0;
    printf("%s", r ? "valid" : "invalid");
    return 0;
}