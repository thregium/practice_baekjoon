#include <stdio.h>
#include <stdlib.h>

/*
문제 : 10 * 10 크기의 'o'와 'x'로 이루어진 배열이 주어진다. 이때, 주어진 좌표에서 'o'와 같은 행 또는 열이 아니게 되는
가장 가까운 행 또는 열 까지의 거리를 구한다. 그러한 칸이 배열 내에 존재하는 경우만 주어진다.

해결 방법 : 배열에서 'o'가 있는 지점과 같은 행 또는 열을 체크한다. 그 다음, 모든 칸을 돌며 체크되지 않은 칸 가운데
원래 주어진 좌표에서 가장 가까운 곳을 찾으면 된다.

주요 알고리즘 : 브루트 포스, 기하학

출처 : 경찰대 2019 J번
*/

char s[16][16], chk[16][16];

int main(void) {
    int x, y, r = 99;
    scanf("%d %d", &x, &y);
    for (int i = 0; i < 10; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < 10; j++) {
            if (s[i][j] == 'o') {
                for (int xx = 0; xx < 10; xx++) chk[xx][j] = 1;
                for (int yy = 0; yy < 10; yy++) chk[i][yy] = 1;
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (chk[i - 1][j - 1]) continue;
            if (abs(i - x) + abs(j - y) < r) r = abs(i - x) + abs(j - y);
        }
    }
    printf("%d", r);
    return 0;
}