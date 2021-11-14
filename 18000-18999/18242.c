#include <stdio.h>
#define INF 1012345678

/*
문제 : N * M(N, M <= 100) 크기의 배열에 '.'과 '#'으로 이루어진 형태가 있다. '#'가 시력 검사의 형태로 되어 있다면
빈 칸이 있는 방향을 구한다.

해결 방법 : '#'가 있는 좌표 가운데 X와 Y좌표의 최대, 최솟값을 구한다. 그 다음, 수평 또는 수직 구멍을 찾고
그 곳이 어느 줄에 있는지를 확인해 방향을 구한다.

주요 알고리즘 : 구현, 애드 혹

출처 : 한양대E 2019Z E번
*/

char s[128][128];

int main(void) {
    int n, m, xl = INF, yl = INF, xh = -1, yh = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                if (i < xl) xl = i;
                if (i > xh) xh = i;
                if (j < yl) yl = j;
                if (j > yl) yh = j;
            }
        }
    }
    if (xh < 0) return 1;
    for (int i = 0; i < m - 2; i++) {
        if (s[xl][i] == '#' && s[xl][i + 1] == '.' && s[xl][i + 2] == '#') printf("UP");
        if (s[xh][i] == '#' && s[xh][i + 1] == '.' && s[xh][i + 2] == '#') printf("DOWN");
    }
    for (int i = 0; i < n - 2; i++) {
        if (s[i][yl] == '#' && s[i + 1][yl] == '.' && s[i + 2][yl] == '#') printf("LEFT");
        if (s[i][yh] == '#' && s[i + 1][yh] == '.' && s[i + 2][yh] == '#') printf("RIGHT");
    }
    return 0;
}