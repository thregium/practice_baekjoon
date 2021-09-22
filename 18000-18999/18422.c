#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 격자에 서로 겹치거나 인접하지 않은 직사각형 형태의 *들이 있다.
이때, 직사각형 형태의 * 덩어리가 몇 개인지 구한다.

해결 방법 : 왼쪽 위부터 차례로 내려가며 확인한다. *을 찾은 경우 해당 지점에서 시작해 만들 수 있는 가장 큰 직사각형을 찾고
그 직사각형을 전부 .로 바꾸어 준다. 그와 같이 결괏값을 1 올린다. 이를 전체 영역에 대해 확인하면 직사각형의 개수를 알 수 있다.

주요 알고리즘 : 구현, 그리디 알고리즘

출처 : COCI 19/20#5 1번
*/

char s[128][128];

int main(void) {
    int n, m, r = 0, sx, sy;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '*') continue;
            sx = 0, sy = 0;
            while (s[i + sx][j] == '*') sx++;
            while (s[i][j + sy] == '*') sy++;
            for (int x = i; x < sx + i; x++) {
                for (int y = j; y < sy + j; y++) {
                    s[x][y] = '.';
                }
            }
            r++;
        }
    }
    printf("%d", r);
    return 0;
}