#include <stdio.h>

/*
���� : N * M(N, M <= 100) ũ���� ���ڿ� �ִ� �� ĭ�� ���� 10000 ������ ������ ���� �ִ�.
K(K <- 4)���� ĭ�� �����¿�� �������� �ʰ� ������ �� �� ĭ�鿡 �ִ� ���� ���� �ִ��� ���Ѵ�.

�ذ� ��� : K�� 4 ���ϱ� ������ ��� ĭ�� �����ϴ� ��� ��츦 �õ��غ��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : baekjoon
*/

int num[16][16], chk[16][16];
int dxy[5][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0} };
int best = -103000;

void track(int n, int m, int r, int c, int k, int s) {
    if (k == 0) {
        if (s > best) best = s;
        return;
    }
    for (int i = r; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == r && j < c) continue;
            if (chk[i][j]) continue;
            for (int d = 0; d < 5; d++) chk[i + dxy[d][0]][j + dxy[d][1]]++;
            track(n, m, i, j + 1, k - 1, s + num[i][j]);
            for (int d = 0; d < 5; d++) chk[i + dxy[d][0]][j + dxy[d][1]]--;
        }
    }
}

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    track(n, m, 1, 1, k, 0);
    printf("%d", best);
    return 0;
}