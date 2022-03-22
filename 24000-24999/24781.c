#include <stdio.h>

/*
���� : 4���� ���ϰ� ��� ���� �̿��� �ϴ� ������ �ִ�. �ֻ����� ������ 1 ~ 4�� ���� ������
4���� ���� ������ �����Ͽ� ���� ������ �ִ� ��츸 ������ 1�� �����Ѵ�. 5�� ���� ������
���� ���� ������ 1�� �����Ѵ�. 6�� ���� ������ ��͸� 1ĭ ������ �ű��. ��Ͱ� 0�� ĭ�� �����ϸ�
���� �ǰ�, �� ���� ������ ���� �����ϸ� �̱�� �ȴ�.
�� ������ ������ 4�� ���ϰ�, ����� �Ÿ��� 8 ������ ��, �̱� Ȯ���� ���Ѵ�.

�ذ� ��� : �� ���� ������ ������ ����� �Ÿ����� Ȯ���� ���̳��� ���α׷����� �̿��� ���Ѵ�.
Ȯ���� �ֻ����� ������ �� ����� ������ Ȯ���� ���� ���ϰ� ���°� ���ϴ� ����� ���� ������ ���� �ȴ�.
���°� ������ �ʴ� ���� ��ܷ� �ؾ� �Կ� �����Ѵ�.

�ֿ� �˰��� : ����, Ȯ����, DP

��ó : VTH 2015 G��
*/

double mem[5][5][5][5][9];

double dp(int r, int g, int b, int y, int s) {
    if (s == 0) return mem[r][g][b][y][s] = 0.0;
    else if (r + g + b + y == 0) return mem[r][g][b][y][s] = 1.0;
    else if (mem[r][g][b][y][s] >= -0.5) return mem[r][g][b][y][s];
    double res = 0.0;
    int count = 2;
    if (r > 0) {
        res += dp(r - 1, g, b, y, s);
        count++;
    }
    if (g > 0) {
        res += dp(r, g - 1, b, y, s);
        count++;
    }
    if (b > 0) {
        res += dp(r, g, b - 1, y, s);
        count++;
    }
    if (y > 0) {
        res += dp(r, g, b, y - 1, s);
        count++;
    }
    if (r >= g && r >= b && r >= y) res += dp(r - 1, g, b, y, s);
    else if (g >= r && g >= b && g >= y) res += dp(r, g - 1, b, y, s);
    else if (b >= r && b >= g && b >= y) res += dp(r, g, b - 1, y, s);
    else if (y >= r && y >= g && y >= b) res += dp(r, g, b, y - 1, s);
    res += dp(r, g, b, y, s - 1);
    return mem[r][g][b][y][s] = res / count;
}

int main(void) {
    int r, g, b, y, s;
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            for (int k = 0; k <= 4; k++) {
                for (int l = 0; l <= 4; l++) {
                    for (int m = 0; m <= 8; m++) mem[i][j][k][l][m] = -1.0;
                }
            }
        }
    }
    scanf("%d %d %d %d %d", &r, &g, &b, &y, &s);
    printf("%.9f", dp(r, g, b, y, s));
    return 0;
}