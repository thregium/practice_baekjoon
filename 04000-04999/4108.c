#include <stdio.h>

/*
문제 : R * C(R, C <= 100) 크기의 격자에서 지뢰가 있는 칸들이 주어질 때, 지뢰가 없는 칸들 주변에
지뢰가 몇 개인지 각각 구한 후 주위 칸수에 맞게 출력한다.

해결 방법 : 각 칸에 지뢰가 있는지 확인하고 있다면 그대로 출력, 없다면 주변 칸에서 지뢰가 있는 칸을 찾아 개수를 세고 그 값을 출력한다.

주요 알고리즘 : 구현

출처 : SEUSA 2009 E번
*/

char mines[128][128];
int dxy[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };

int main(void) {
    int r, c, cnt;
    while (1) {
        scanf("%d %d", &r, &c);
        if (r == 0) break;
        for (int i = 1; i <= r; i++) {
            scanf("%s", mines[i] + 1);
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (mines[i][j] == '*') {
                    printf("*");
                    continue;
                }
                cnt = 0;
                for (int d = 0; d < 8; d++) {
                    if (mines[i + dxy[d][0]][j + dxy[d][1]] == '*') cnt++;
                }
                printf("%d", cnt);
            }
            printf("\n");
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) mines[i][j] = '\0';
        }
    }
    return 0;
}