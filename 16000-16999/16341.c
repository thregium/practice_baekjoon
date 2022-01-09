#include <stdio.h>
#include <math.h>

/*
���� : ü���� ���� ����� ������ ����Ʈ�� ���� �ٸ� ĭ�� �ִ�. ��� ����Ʈ���� �����̸� ���� ����� ĭ�� ��� ����Ʈ�� �̱�ٸ�,
��� ����Ʈ�� �̱� Ȯ���� ������ ���Ѵ�. �̱� Ȯ���� ���̰� 10^-6 ������ ��� ��� ������ ����.
�� ����Ʈ�� ������ �� �ִ� ��� ĭ ��� �������ϰ� �����δ�.

�ذ� ��� : �ϸ��� �� ����Ʈ�� �ð��� ��ġ�� ���� Ȯ���� ����ϸ� ���̳��� ���α׷����� �����Ѵ�.
���� �� ����Ʈ�� ���� ĭ�� �ְ� �ȴٸ� �ش� ���� Ȯ���Ͽ� �̱�� �� ����Ʈ�� �·��� �����ش�.
�̸� ����� �ݺ��� ���� �·��� Ȯ���ϰ� ����ϸ� �ȴ�.

�ֿ� �˰��� : DP, Ȯ����

��ó : CTU 2018 H��
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
