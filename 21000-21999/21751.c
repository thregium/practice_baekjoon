#include <stdio.h>

/*
문제 : M * N(M, N <= 100) 크기의 칸에서 지뢰찾기를 한다. 근처 또는 해당 칸에 지뢰가 있는 칸을 1, 없는 칸을 0이라고 할 때,
해당하는 형태로 지뢰를 놓을 수 있는지 확인하고, 있다면 지뢰의 배치와 주변 지뢰의 칸 수를 구한다.

해결 방법 : 먼저 해당 칸과 주변 모든 칸이 지뢰인 칸들 전체에 지뢰를 배치한다.(지뢰가 있을 수 있는 모든 칸)
그 다음 1인 칸들 중 근처에 지뢰가 없는 칸이 있는지 찾는다. 있다면 그 곳에는 어떻게도 지뢰 근처를 만들 수 없다는 의미이므로
배치가 불가능하다. 배치가 가능하다면 모든 칸에 대해 근처의 지뢰 수를 센 다음 지뢰밭의 모습을 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 구현, 구성적

출처 : ROI 2004H E번
*/

int opens[128][128], mines[128][128];
int dxy[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i <= m + 1; i++) {
        for (int j = 0; j <= n + 1; j++) opens[i][j] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &opens[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (opens[i][j]) mines[i][j] = -1;
            for (int k = 0; k < 8; k++) {
                if (!opens[i + dxy[k][0]][j + dxy[k][1]]) mines[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (mines[i][j] < 0) continue;
            for (int k = 0; k < 8; k++) {
                if (mines[i + dxy[k][0]][j + dxy[k][1]] < 0) mines[i][j]++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (mines[i][j] == 0 && opens[i][j] == 1) {
                printf("No solution");
                return 0;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (mines[i][j] < 0) printf("*");
            else if (mines[i][j] == 0) printf(".");
            else printf("%d", mines[i][j]);
        }
        printf("\n");
    }
    return 0;
}