#include <stdio.h>

/*
문제 : N * N(N <= 10) 크기의 지뢰찾기 판에서 지뢰가 있는 칸과 열린 칸들이 주어질 때, 지뢰찾기 판의 상태를 출력한다.
지뢰가 있는 칸이 열렸다면 모든 지뢰가 표시되어야 하고, 그 외의 열린 칸들은 주위의 지뢰 수가 표시되어야 한다.
그 외의 칸들은 닫힌 상태 그대로여야 한다.

해결 방법 : 먼저 지뢰가 열렸는지를 확인한다. 그 다음으로는 지뢰찾기 판을 돌면서 지뢰가 있는 칸이라면
지뢰가 열렸을 경우에만 표시한다. 그 외의 닫힌 칸이라면 그대로 두고, 열린 칸이라면 주위의 지뢰 수를 센 다음
그 수를 출력하면 된다.

주요 알고리즘 : 구현

출처 : waterloo 991002 A번
*/

char mf[16][16], op[16][16];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

int main(void) {
    int n, mine = 0, cnt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", mf[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", op[i]);
        for (int j = 0; j < n; j++) {
            if (op[i][j] == 'x' && mf[i][j] == '*') mine = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mine && mf[i][j] == '*') printf("*");
            else if (op[i][j] != 'x') printf(".");
            else {
                cnt = 0;
                for (int d = 0; d < 8; d++) {
                    if (i + dxy[d][0] < 0 || j + dxy[d][1] < 0) continue;
                    if (mf[i + dxy[d][0]][j + dxy[d][1]] == '*') cnt++;
                }
                printf("%d", cnt);
            }
        }
        printf("\n");
    }
    return 0;
}