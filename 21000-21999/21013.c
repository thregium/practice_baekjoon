#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
���� : N * N(N <= 1000) ũ���� �迭�� 0���� N������ ���� ä���ִ´�. ���� ���ǿ� �°� ä���ִ� �����
�ִ� �� Ȯ���ϰ�, �ִٸ� �׷��� ����� ����Ѵ�.
1. ��� ����, ����, �밢���� �� ���� ���ƾ� �Ѵ�.
2. 0���� ū ��� �� i�� i�� �̳��� �����ؾ� �Ѵ�.
3. 0���� ū ���� �ٸ� ���� 2�� �̻� ���;� �Ѵ�.

�ذ� ��� : 4������ ũ�⿡���� �׷��� ����� ����. 5 �̻��� ũ�⿡���� ���� ���� ����� �ִµ�,
������ ������δ� Ȧ���� ¦���� ���� ������, N - 2���� ���� ��� N���� ä���, ������ ĭ����
N / 2 - 1�� N / 2 + 1�� ����� �Ἥ ä��� ����� �ִ�.
�ڼ��� ä��� ����� �ڵ带 �����Ѵ�.

�ֿ� �˰��� : ����, ������

��ó : INC 2020 E��
*/

int cnt[1024], a[1024][1024];

int verify(int n) {
    int ls = 0, ts = 0, nc = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > i) return 0;
        else if (cnt[i] > 0) nc++;
    }
    if (nc < 2) return 0;
    for (int i = 0; i < n; i++) ls += a[i][0];
    for (int i = 0; i < n; i++) {
        ts = 0;
        for (int j = 0; j < n; j++) {
            ts += a[i][j];
        }
        if (ts != ls) return 0;
        ts = 0;
        for (int j = 0; j < n; j++) {
            ts += a[j][i];
        }
        if (ts != ls) return 0;
    }
    ts = 0;
    for (int i = 0; i < n; i++) ts += a[i][i];
    if (ts != ls) return 0;
    ts = 0;
    for (int i = 0; i < n; i++) ts += a[i][n - i - 1];
    if (ts != ls) return 0;
    return 1;
}

void track(int n, int x, int y, int z) {
    if (x >= n) {
        if (verify(n)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
                printf("\n");
            }
            printf("\n");
        }
        return;
    }
    int s;
    for (int i = 0; i <= n; i++) {
        if (i > 0 && cnt[i] >= i) continue;
        a[x][y] = i;
        s = 0;
        for (int j = 0; j <= y; j++) s += a[x][j];
        if (s > z || (y == n - 1 && s < z)) continue;
        s = 0;
        for (int j = 0; j <= x; j++) s += a[j][y];
        if (s > z || (x == n - 1 && s < z)) continue;
        cnt[i]++;
        track(n, y == n - 1 ? x + 1 : x, y == n - 1 ? 0 : y + 1, z);
        cnt[i]--;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    if (n > 2 && (n % 2 == 0)) return 1;
    if (n <= 4) {
        printf("-1");
        return 0;
    }
    /*
    for (int i = 0; i <= n * n; i++) {
        track(n, 0, 0, i);
    }
    */
    if (n & 1) {
        a[n >> 1][n >> 1] = n;
        a[0][(n >> 1) - 1] = (n >> 1);
        a[0][(n >> 1) + 1] = (n >> 1) + 1;
        a[n - 1][(n >> 1) - 1] = (n >> 1) + 1;
        a[n - 1][(n >> 1) + 1] = (n >> 1);
        for (int i = 1; i < (n >> 1); i++) a[i][i - 1] = n;
        for (int i = (n >> 1) + 1; i < n - 1; i++) a[i][i + 1] = n;
    }
    else {
        a[0][0] = n;
        a[1][n - 2] = n;
        a[2][1] = n;
        a[3][n - 1] = n;
        for (int i = 4; i <= (n >> 1); i++) a[i][i - 2] = n;
        if (n == 8) a[(n >> 1) + 1][3] = n;
        else a[(n >> 1) + 1][n - 3] = n;
        for (int i = (n >> 1) + 2; i < n - 2; i++) a[i][i - 1] = n;
        if (n == 8) {
            a[6][4] = 6;
            a[6][5] = 2;
            a[7][4] = 2;
            a[7][5] = 6;
        }
        else {
            a[n - 2][n >> 1] = (n >> 1) - 1;
            a[n - 2][(n >> 1) - 1] = (n >> 1) + 1;
            a[n - 1][n >> 1] = (n >> 1) + 1;
            a[n - 1][(n >> 1) - 1] = (n >> 1) - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
            cnt[a[i][j]]++;
        }
        printf("\n");
    }
    if (!verify(n)) {
        printf("ERROR!");
        return 1;
    }
    return 0;
}