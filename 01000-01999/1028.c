#include <stdio.h>

/*
문제 : R * C(R, C <= 750) 크기의 칸에서 가장 큰 다이아몬드 모양의 크기를 출력한다.

해결 방법 : 다이아몬드 모양은 대각선 형태로만 이루어져 있으므로 각 지점에서 나올 수 있는
가장 긴 대각선의 길이를 구한다. 맨 윗줄부터 시작해서 대각선을 이을 수 있으면 +1, 없으면 0으로 초기화한다.
대각선을 전부 구하면, 모든 지점에 대해 다이아몬드를 만들 수 있는지 검사하고, 그 중 가장 큰 값을 출력한다.

주요 알고리즘 : 다이나믹 프로그래밍, 브루트 포스
*/

char mine[768][768];
int diag[2][768][768];

int main(void) {
    int r, c, x = 0, y = 0, z, res = 0;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf("%s", mine[i] + 1);
        for (int j = 1; j <= c; j++) {
            mine[i][j] -= '0';
        }
    }
    if (r < c) z = (r + 1) / 2; //다이아몬드의 이론상 최대 크기 계산
    else z = (c + 1) / 2;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (!diag[0][i - 1][j + 1]) {
				//오른 쪽 위가 빈 경우
                x = i;
                y = j;
                while (mine[x][y]) {
                    x++;
                    y--;
                    diag[0][i][j]++;
                }
            }
            else diag[0][i][j] = diag[0][i - 1][j + 1] - 1; //오른쪽 위에 다이아몬드가 있는 경우
            if (!diag[1][i - 1][j - 1]) {
				//왼쪽 위가 빈 경우
                x = i;
                y = j;
                while (mine[x][y]) {
                    x++;
                    y++;
                    diag[1][i][j]++;
                }
            }
            else diag[1][i][j] = diag[1][i - 1][j - 1] - 1; //왼쪽 위에 다이아몬드가 있는 경우
        }
    }

    
    for (int i = 1; i <= z; i++) {
		//크기 순으로 탐색
        for (int j = 1; j <= r - 2 * (i - 1); j++) {
            for (int k = i; k <= c - i + 1; k++) {
                if (diag[0][j][k] >= i && diag[1][j][k] >= i && diag[0][j + i - 1][k + i - 1] >= i && diag[1][j + i - 1][k - i + 1] >= i) res = i;
				//현재 크기에서 모든 대각선의 길이가 충분한 경우 결괏값 변경
            }
        }
    }
    printf("%d", res);
    return 0;
}