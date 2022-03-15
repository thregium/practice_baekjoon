#include <stdio.h>

/*
���� : N(3 <= N <= 9, Ȧ��)���� ���� ��⸦ �Ѵ�. �� ���� ���и��� ������ ���ºδ� �Ͼ�� �ʴ´�.
�̶�, ��������� ����� M(1 <= M <= N * (N - 1) / 2)�� �־��� ��, ��� ���� ���м��� ���� �Ǵ� ����
�� ������ ���� �� �ִ� �� ���Ѵ�.

�ذ� ��� : N�� 9�̰� M�� 1�� ��쿡�� ���ƾ� �� 160������ ���̹Ƿ� ��Ʈ��ŷ�� ����
��� ��츦 �� ���� �غ��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : JDC 2018 D��
*/

int wl[16][16];

int track(int n, int a, int b) {
    int c, r;
    if (a == b) {
        if (a == n) return 1;
        else return track(n, a, b + 1);
    }
    if (a > b || (a == n && b > n)) return 1;

    if (wl[a][b]) {
        if (b == n) {
            c = 0;
            for (int i = 1; i <= n; i++) c += wl[a][i];
            if (c) return 0;
            else return track(n, a + 1, a + 2);
        }
        else return track(n, a, b + 1);
    }
    else {
        r = 0;
        if (b == n) {
            wl[a][b] = 1, wl[b][a] = -1;
            c = 0;
            for (int i = 1; i <= n; i++) c += wl[a][i];
            if (!c) r += track(n, a + 1, a + 2);
            wl[a][b] = -1, wl[b][a] = 1;
            c = 0;
            for (int i = 1; i <= n; i++) c += wl[a][i];
            if (!c) r += track(n, a + 1, a + 2);
            wl[a][b] = 0, wl[b][a] = 0;
        }
        else {
            wl[a][b] = 1, wl[b][a] = -1;
            r += track(n, a, b + 1);
            wl[a][b] = -1, wl[b][a] = 1;
            r += track(n, a, b + 1);
            wl[a][b] = 0, wl[b][a] = 0;
        }
        return r;
    }
}

int main(void) {
    int n, m, a, b;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            wl[a][b] = 1;
            wl[b][a] = -1;
        }
        printf("%d\n", track(n, 1, 2));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) wl[i][j] = 0;
        }
    }
    return 0;
}