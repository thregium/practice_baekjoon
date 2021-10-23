#include <stdio.h>

/*
문제 : N(N <= 100)개의 10 * 10 크기 색종이를 100 * 100 크기 도화지에 붙였다. 색종이는 도화지를 벗어나지 않는다.
이때, 붙인 색종이가 붙이지 않는 부분과 이루는 둘레를 구한다.

해결 방법 : 색종이를 붙이며 붙인 칸들을 체크해 놓는다. 그 다음, 각 칸들을 돌면서 붙인 칸들에 대해
주변 칸이 붙이지 않은 칸인 경우 두 칸 사이 변은 둘레의 일부이므로 결괏값에 1씩 더해주면 된다.
모든 둘레는 붙인 칸과 붙이지 않은 칸 사이에만 있으므로 그 값이 답이 된다.

주요 알고리즘 : 구현

출처 : 정올 2007지 중2번
*/

int chk[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, x, y, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x <= 0 || y <= 0 || x > 100 || y > 100) return 1;
        for (int xx = x; xx < x + 10; xx++) {
            for (int yy = y; yy < y + 10; yy++) {
                chk[xx][yy] = 1;
            }
        }
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (!chk[i][j]) continue;
            for (int d = 0; d < 4; d++) {
                if (chk[i + dxy[d][0]][j + dxy[d][1]]) continue;
                else r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}