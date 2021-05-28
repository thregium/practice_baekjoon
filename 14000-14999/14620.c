#include <stdio.h>

/*
���� : N * N(N <= 10) ũ���� ���ڿ��� ���� ����� ��ġ�� �ʰ� 3�� ����, �� ���� ���� ���� ���� ���� �۰� �� ��, �� ���� ���Ѵ�.

�ذ� ��� : ��� ĭ�� ���� ���� ��ġ�� �ʰ� ���ƺ��� ���� ���� ���� ���� ã�´�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : ���ϴ� 2017 J��
*/

int g[16][16], s[16][16];
int dxy[5][2] = { {0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, best = 12345;

track(int a, int x, int m) {
    if (a == x) {
        if (m < best) best = m;
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (s[i][j] || s[i][j - 1] || s[i - 1][j] || s[i][j + 1] || s[i + 1][j]) continue;
            for (int k = 0; k < 5; k++) {
                s[i + dxy[k][0]][j + dxy[k][1]] = 1;
                m += g[i + dxy[k][0]][j + dxy[k][1]];
            }
            track(a, x + 1, m);
            for (int k = 0; k < 5; k++) {
                s[i + dxy[k][0]][j + dxy[k][1]] = 0;
                m -= g[i + dxy[k][0]][j + dxy[k][1]];
            }
        }
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    track(3, 0, 0);
    printf("%d", best);
    return 0;
}