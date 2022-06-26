#include <stdio.h>

/*
문제 : N * M(N, M <= 1000) 크기의 공간에 벽과 빈 칸이 있다. 빈 칸과 인접한 벽에 2칸 길이의 그림을
겹치지 않도록 최대한 걸 때, 걸 수 있는 그림의 최대 개수를 구한다.

해결 방법 : 각 방향에 대해 연속한 같은 형태의 벽의 길이를 각각 구한다. 그 길이 / 2를 버림한 것이
그 벽에 걸 수 있는 그림의 최대 개수이다.

주요 알고리즘 : 구현

출처 : CHCI 2003N2J 2번
*/

char s[1024][1024];

int main(void) {
    int n, m, l, res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 1; i < n; i++) {
        l = 0;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.' && s[i - 1][j] == 'X') l++;
            else {
                res += (l >> 1);
                l = 0;
            }
        }
        res += (l >> 1);
        l = 0;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'X' && s[i - 1][j] == '.') l++;
            else {
                res += (l >> 1);
                l = 0;
            }
        }
        res += (l >> 1);
    }
    for (int i = 1; i < m; i++) {
        l = 0;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == '.' && s[j][i - 1] == 'X') l++;
            else {
                res += (l >> 1);
                l = 0;
            }
        }
        res += (l >> 1);
        l = 0;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == 'X' && s[j][i - 1] == '.') l++;
            else {
                res += (l >> 1);
                l = 0;
            }
        }
        res += (l >> 1);
    }
    printf("%d", res);
    return 0;
}