#include <stdio.h>

/*
문제 : H * W(H, W <= 100) 크기의 격자에서 구름에 1분에 한 칸씩 동쪽으로 움직일 때, 각 칸에 구름이 언제 처음 들어오게 되는지 구한다.

해결 방법 : 각 줄별로 생각해봤을 때, 왼쪽에 구름이 없다면 그 칸에는 구름이 들어올 일이 없다. 만약 왼쪽에 구름이 있다면
가장 가까운 칸의 구름이 들어오는 시각이 처음 들어오는 시각이 되는데, 그 시각은 왼쪽 칸의 시각에서 1분 뒤이다.
그리고 그 칸에 구름이 있는 경우에는 0분으로 초기화된다.

주요 알고리즘 : 구현, DP

출처 : JOI 2015예 3번
*/

char clouds[128];
int r[128];

int main(void) {
    int h, w;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", clouds);
        r[0] = (clouds[0] == 'c') - 1;
        printf("%d ", r[0]);
        for (int j = 1; j < w; j++) {
            if (clouds[j] == 'c') r[j] = 0;
            else if (r[j - 1] < 0) r[j] = -1;
            else r[j] = r[j - 1] + 1;
            printf("%d ", r[j]);
        }
        printf("\n");
    }
    return 0;
}