#include <stdio.h>

/*
문제 : R * C(R, C <= 10) 크기의 지도에서 주위 3칸 이상이 바다인 땅은 바다가 된다고 할 때,
그 후 모든 땅을 포함하는 가장 작은 직사각형 영역의 지도를 출력한다.

해결 방법 : 우선 각 칸이 바다가 되는지 땅으로 남는 지 저장해둔 다음, 출력할 범위를 찾고,
그 범위를 출력하면 된다. 바다가 되는지 여부에는 방향 배열을 활용하면 좋다.

주요 알고리즘 : 구현

출처 : COCI 12/13#5 2번
*/

char now[16][16], fut[16][16];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int r, c, cnt, xl = 16, xh = -1, yl = 16, yh = -1;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf("%s", now[i] + 1);
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cnt = 0;
            for (int k = 0; k < 4; k++) {
                cnt += (now[i + dxy[k][0]][j + dxy[k][1]] != 'X');
            }
            if (cnt >= 3 || now[i][j] == '.') fut[i][j] = '.';
            else fut[i][j] = 'X';
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (fut[i][j] != 'X') continue;
            if (i < xl) xl = i;
            if (i > xh) xh = i;
            if (j < yl) yl = j;
            if (j > yh) yh = j;
        }
    }

    for (int i = xl; i <= xh; i++) {
        for (int j = yl; j <= yh; j++) {
            printf("%c", fut[i][j]);
        }
        printf("\n");
    }
    return 0;
}