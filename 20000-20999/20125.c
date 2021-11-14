#include <stdio.h>

/*
문제 : N * N(N <= 1000) 크기의 배열에 사람 모양이 주어질 때, 몸통의 위치와 왼팔, 오른팔, 허리, 왼다리, 오른다리의 길이를
각각 구한다.

해결 방법 : 상하좌우로 '*'가 있는 곳을 찾으면 그곳이 몸통의 위치이다. 그 이후로는 몸통의 위치를 이용해
왼팔, 오른팔, 허리, 왼다리, 오른다리의 길이를 구할 수 있다.

주요 알고리즘 : 구현, 애드 혹

출처 : 연세대 2020 B번
*/

char s[1024][1024];

int main(void) {
    int n, x = -1, y = -1, la = 0, ra = 0, w = 0, ll = 0, rl = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (s[i][j] == '*' && s[i + 1][j] == '*' && s[i][j + 1] == '*' && s[i - 1][j] == '*' && s[i][j - 1] == '*') {
                if (x >= 0) return 1;
                x = i;
                y = j;
            }
        }
    }
    if (x < 0) return 2;
    printf("%d %d\n", x + 1, y + 1);
    for (int i = 0; i < y; i++) {
        if (s[x][i] == '*') la++;
    }
    for (int i = y + 1; i < n; i++) {
        if (s[x][i] == '*') ra++;
    }
    for (int i = x + 1; i < n; i++) {
        if (s[i][y] == '*') w++;
    }
    for (int i = x + 1; i < n; i++) {
        if (s[i][y - 1] == '*') ll++;
    }
    for (int i = x + 1; i < n; i++) {
        if (s[i][y + 1] == '*') rl++;
    }
    printf("%d %d %d %d %d", la, ra, w, ll, rl);
    return 0;
}