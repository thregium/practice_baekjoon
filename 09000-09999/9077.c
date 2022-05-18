#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 100000)���� ���ڰ� ��� ���� 10000 �̳� ���� �ƴ� ���� ���� �ִ�.
10 * 10 ũ���� ���� �ȿ� ���ڰ� �ִ� �� �� �ִ� �� ���Ѵ�. ��� ���ڴ� ���� �ٸ� ���� �ִ�.

�ذ� ��� : �� ��ǥ�� ���� �� �迭�� ����� �� 10 * 10 ���� ���� ���ڸ� (����) ������ ã�� �� �ִ�.
�� ���ڿ� ���� ���� 5 * 5 ĭ�� �߽����� �ϴ� ��� �簢�� ������ ���� ���� ������ ����
�� ��� ���� ���� ���� ������ ���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ���� ��

��ó : Seoul 2004I C��
*/

int mine[10240][10240], pos[103000][2];

int big(int a, int b) {
    return a > b ? a : b;
}

int getsum(int x1, int y1, int x2, int y2) {
    return mine[x2][y2] - mine[x1 - 1][y2] - mine[x2][y1 - 1] + mine[x1 - 1][y1 - 1];
}

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &pos[i][0], &pos[i][1]);
            pos[i][0] += 15, pos[i][1] += 15;
            mine[pos[i][0]][pos[i][1]]++;
        }
        for (int i = 1; i < 10240; i++) {
            for (int j = 1; j < 10240; j++) mine[i][j] += mine[i][j - 1];
        }
        for (int i = 1; i < 10240; i++) {
            for (int j = 1; j < 10240; j++) mine[j][i] += mine[j - 1][i];
        }

        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = -5; j <= 5; j++) {
                for (int k = -5; k <= 5; k++) {
                    r = big(r, getsum(pos[i][0] + j - 5, pos[i][1] + k - 5,
                        pos[i][0] + j + 5, pos[i][1] + k + 5));
                }
            }
        }
        printf("%d\n", r);

        memset(mine, 0, sizeof(mine));
    }
    return 0;
}