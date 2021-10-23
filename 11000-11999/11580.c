#include <stdio.h>

/*
문제 : N(N <= 1000)회 동서남북으로 1칸씩 이동한 기록이 주어질 때, 이동하는 과정에 도달한 적이 있는 격자점의 개수를 구한다.
시작과 끝점을 모두 포함한다.

해결 방법 : 2000 * 2000 이상의 크기인 배열을 선언한 후 가운데 점에서부터 이동한 칸들을 모두 저장한다.
그 후, 배열 전체에서 이동한 적이 있는 칸들을 세면 된다.

주요 알고리즘 : 구현, 시뮬레이션?

출처 : 인하대 2015 F번
*/

char s[1024], chk[2048][2048];

int main(void) {
    int n, x = 1024, y = 1024, r = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        chk[x][y] = 1;
        if (s[i] == 'N') y++;
        else if (s[i] == 'E') x++;
        else if (s[i] == 'S') y--;
        else if (s[i] == 'W') x--;
        else return 1;
        chk[x][y] = 1;
    }
    for (int i = 0; i < 2048; i++) {
        for (int j = 0; j < 2048; j++) {
            if (chk[i][j]) r++;
        }
    }
    printf("%d", r);
    return 0;
}