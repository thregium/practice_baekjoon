#include <stdio.h>
#include <math.h>

/*
문제 : 체스판 위에 흰색과 검은색 나이트가 서로 다른 칸에 있다. 흰색 나이트부터 움직이며 먼저 상대의 칸을 밟는 나이트가 이긴다면,
어느 나이트가 이길 확률이 높은지 구한다. 이길 확률의 차이가 10^-6 이하인 경우 비긴 것으로 본다.
각 나이트는 움직일 수 있는 모든 칸 가운데 무작위하게 움직인다.

해결 방법 : 턴마다 두 나이트의 시간별 위치에 대한 확률을 기록하며 다이나믹 프로그래밍을 진행한다.
만약 두 나이트가 같은 칸에 있게 된다면 해당 턴을 확인하여 이기는 쪽 나이트의 승률을 높여준다.
이를 충분히 반복한 다음 승률을 확인하고 출력하면 된다.

주요 알고리즘 : DP, 확률론

출처 : CTU 2018 H번
*/

int mcnt[8][8];
double mem[1024][8][8][2];
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };

int main(void) {
    int a, b, c, d, x, y;
    double ww = 0.0, bw = 0.0;

    scanf("%d %d%d %d", &a, &b, &c, &d);
    a--, b--, c--, d--;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int d = 0; d < 8; d++) {
                x = i + dxy[d][0], y = j + dxy[d][1];
                if (x < 0 || y < 0 || x >= 8 || y >= 8) continue;
                mcnt[i][j]++;
            }
        }
    }
    mem[0][a][b][0] = 1.0;
    mem[0][c][d][1] = 1.0;

    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (i & 1) {
                    ww += mem[i][j][k][1] * mem[i][j][k][0];
                    mem[i + 1][j][k][0] = mem[i][j][k][0] * (1.0 - mem[i][j][k][1]);
                    for (int d = 0; d < 8; d++) {
                        x = j + dxy[d][0], y = k + dxy[d][1];
                        if (x < 0 || y < 0 || x >= 8 || y >= 8) continue;
                        mem[i + 1][j + dxy[d][0]][k + dxy[d][1]][1] += mem[i][j][k][1] * 1.0 / mcnt[j][k];
                    }
                }
                else {
                    bw += mem[i][j][k][0] * mem[i][j][k][1];
                    mem[i + 1][j][k][1] = mem[i][j][k][1] * (1.0 - mem[i][j][k][0]);
                    for (int d = 0; d < 8; d++) {
                        x = j + dxy[d][0], y = k + dxy[d][1];
                        if (x < 0 || y < 0 || x >= 8 || y >= 8) continue;
                        mem[i + 1][j + dxy[d][0]][k + dxy[d][1]][0] += mem[i][j][k][0] * 1.0 / mcnt[j][k];
                    }
                }
            }
        }
    }
    //printf("%.9f %.9f", ww, bw);
    if (fabs(ww - bw) < 1E-6) printf("draw");
    else if (ww > bw) printf("white");
    else printf("black");
    return 0;
}
