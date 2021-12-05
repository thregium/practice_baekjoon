#include <stdio.h>

/*
문제 : 10 * 10 크기의 칸에 성냥개비들을 3 * 3 크기의 격자 형태로 놓았다. 그 후 몇 개의 성냥개비를 뺐을 때,
뺀 성냥개비의 수와 남은 성냥개비들로 만들 수 있는 정사각형의 개수를 구한다.

해결 방법 : 먼저 뺀 성냥개비의 수는 24 - 남은 성냥개비 수를 하면 된다. 남은 성냥개비는 -와 |를 통해 쉽게 구할 수 있다.
정사각형들은 가능한 위치들에 대해 테두리가 전부 -와 |, *로 이루어져 있는지 확인해보면 된다.

주요 알고리즘 : 구현, 브루트 포스
*/

char s[16][16];

int main(void) {
    int a = 48, b = 0, t;
    for (int i = 0; i < 10; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < 10; j++) {
            if (s[i][j] == '-' || s[i][j] == '|') a--;
        }
    }
    if (a & 1) return 1;
    else a >>= 1;
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j <= 3 - i; j++) {
            for (int k = 0; k <= 3 - i; k++) {
                t = 1;
                for (int ii = j * 3; ii <= (i + j) * 3; ii++) {
                    for (int jj = k * 3; jj <= (i + k) * 3; jj++) {
                        if ((ii == j * 3 || ii == (i + j) * 3 || jj == k * 3 || jj == (i + k) * 3) && s[ii][jj] == '.') t = 0;
                    }
                }
                b += t;
            }
        }
    }
    printf("%d %d", a, b);
    return 0;
}