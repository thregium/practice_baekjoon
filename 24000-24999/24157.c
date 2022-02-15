#include <stdio.h>
#define INF 1012345678

/*
���� : N * M(N, M <= 1000) ũ���� ����(-1 <=, <= 100)�� �̷���� �迭���� A * B(A <= N, B <= M) ũ����
���簢���� ���� ���� ���� ���� ���� ���� �� ���� ���Ѵ�. ��, �߰��� -1�� ������ �� �ȴ�.
�׻� -1�� ���� �ʰ� A * B ũ���� ���簢���� ���� ����� ���� ������ ��츸 �־�����.

�ذ� ��� : 2���� ���� ���� ������ ���� ���� �� �ִ�. �迭�� -1 ������ ���� ����
2���� ���� ������ ���� ����, ��� (N - A) * (M - B)���� ���簢���鿡 ���� ���� ���� ����
�ȿ� -1�� ���� �� ���θ� Ȯ���� ����, ���� �ʴ´ٸ� ���� ���� ���� ���� ���� ã�Ƴ����� �ȴ�.

�ֿ� �˰��� : ���� ��

��ó : JOISC 06/07 1-3��
*/

int psum[1024][1024], pops[1024][1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int getsum(int x1, int y1, int x2, int y2) {
    return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
}

int getpop(int x1, int y1, int x2, int y2) {
    return pops[x2][y2] - pops[x1 - 1][y2] - pops[x2][y1 - 1] + pops[x1 - 1][y1 - 1];
}

int main(void) {
    int n, m, a, b, r = INF;
    scanf("%d %d%d %d", &m, &n, &b, &a);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &psum[i][j]);
            if (psum[i][j] < 0) pops[i][j] = pops[i][j - 1] + 1;
            else pops[i][j] = pops[i][j - 1];
            psum[i][j] += psum[i][j - 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            psum[j][i] += psum[j - 1][i];
            pops[j][i] += pops[j - 1][i];
        }
    }
    for (int i = 1; i <= n - a + 1; i++) {
        for (int j = 1; j <= m - b + 1; j++) {
            if (getpop(i, j, i + a - 1, j + b - 1) == 0) {
                r = small(r, getsum(i, j, i + a - 1, j + b - 1));
            }
        }
    }
    if (r == INF) return 1;
    printf("%d", r);
    return 0;
}