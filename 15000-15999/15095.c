#include <stdio.h>

/*
문제 : 5 * 5 크기의 체스판에 나이트들이 놓여 있을 때, 이것이 9-나이트의 해 중 하나인 지 구한다.

해결 방법 : 각 나이트마다 움직일 수 있는 칸들을 전부 확인해 서로 공격받는 경우가 없는 지 확인한다.
또한, 나이트의 개수도 확인해서 9개의 나이트가 전부 놓였는 지도 확인해야 한다.

주요 알고리즘 : 구현

출처 : MidC 2017 A번
*/

char s[16][16];
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };

int main(void) {
    int r = 1, c = 0;
    for (int i = 2; i <= 6; i++) {
        scanf("%s", s[i] + 2);
    }
    for (int i = 2; i <= 6; i++) {
        for (int j = 2; j <= 6; j++) {
            if (s[i][j] == '.') continue;
            c++;
            for (int k = 0; k < 8; k++) {
                if (s[i + dxy[k][0]][j + dxy[k][1]] == 'k') r = 0;
            }
        }
    }
    if (c != 9) r = 0;
    printf("%s", r ? "valid" : "invalid");
    return 0;
}