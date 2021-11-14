#include <stdio.h>

/*
���� : N * N(N <= 50) ũ�� ü���ǿ��� ����Ʈ�� ���� ��ġ�� �־��� ��,
����Ʈ�� K(K <= 50)�� �̵��ϸ� ���� ������ �ʴ� Ȯ���� ���Ѵ�.

�ذ� ��� : �� ĭ�� �̵� Ƚ������ ����Ʈ�� ���� ������ ���� Ȯ���� �����ϸ� ���̳��� ���α׷����� �����Ѵ�.

�ֿ� �˰��� : DP, Ȯ����
*/

double mem[64][64][64];
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
int n;

int isvalid(int x, int y) {
    if (x <= 0 || y <= 0 || x > n || y > n) return 0;
    return 1;
}

double dp(int x, int y, int k) {
    if (mem[x][y][k] > -0.5) return mem[x][y][k];
    if (k == 0) return mem[x][y][k] = 1.0;

    double r = 0.0;
    for (int i = 0; i < 8; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) r += dp(x + dxy[i][0], y + dxy[i][1], k - 1) / 8.0;
    }
    return mem[x][y][k] = r;
}

int main(void) {
    int x, y, k;
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            for (int k = 0; k < 64; k++) mem[i][j][k] = -1.0;
        }
    }
    scanf("%d %d %d %d", &n, &x, &y, &k);
    printf("%.16f", dp(x, y, k));
    return 0;
}