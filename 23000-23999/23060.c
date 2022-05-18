#include <stdio.h>

/*
���� : N * N(N <= 500) ũ���� ü���ǿ��� (X, Y)�� ����Ʈ�� ���� ��, ����Ʈ�� 2 * N^2ȸ �̳���
��� ĭ�� 1ȸ �̻� �湮�ϵ��� �����̴� ����� �ִ� �� ã��, �ִٸ� �׷��� ��� ��� �ϳ��� ���Ѵ�.

�ذ� ��� : V�� ���·� ������ ������ ��� (floor(�� / 2) + ��)�� Ȧ¦���� ���� ĭ��
��� �湮�� �� �ִ�. �̸� �̿��� �׷��� ĭ���� ��� �湮�� ����, �ٽ� (floor(�� / 2) + ��)�� Ȧ¦����
�ٲ� �� �׷��� ĭ���� ���� �湮�Ѵ�. ���� ���·� ���� �̵��� ������ (1, 1)���� �������� �� Ȧ����° ����
��� �湮�ϴ� ���� �����ϴ�. �ٽ� (2, 1)�� ������ ���� ��� ¦����° ���� ���� �������
�湮�� ���ƿ��� �ȴ�.

(1, 1)�� ���ƿ��� ������δ� ���� ��ȭ�� 2�� �̵� ��� (1, 1)�� ��������� ������� ������ �̵��� �Ͽ�
��� ���� ���� ��� 2 ���ϰ� �ǵ��� �� ���� �� ĭ�鿡 ���� (1, 1)�� �����̴� ���� �ִ�.

�� ������ �̵��ϸ� �� N^2 + 2Nȸ �ȿ� �׻� �̵��� �����ϴ�.

�� ����� �� ���¿� ���� ����� ���� ������ �ذ��ϸ� �ȴ�. N�� 2 �Ǵ� 3�� ��� �Ұ����ϰ�,
N�� 1�� ���� ���������� 3 ���Ͽ� ���ؼ��� ���� ���� ó���� �ϴ� ���� ����.

�ֿ� �˰��� : ���̽� ��ũ, ������

��ó : �泲�� 5ȸ F��
*/

int cnt[512][512] = {{1}, }, res[524288][2] = {{1, 1},};
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
int n, rlen = 1;

int moveknight(int* x, int* y, int dir) {
    *x += dxy[dir][0];
    *y += dxy[dir][1];
    if (*x < 1 || *y < 1 || *x > n || *y > n) {
        *x -= dxy[dir][0];
        *y -= dxy[dir][1];
        return 0;
    }
    else {
        res[rlen][0] = *x;
        res[rlen++][1] = *y;
        cnt[*x][*y]++;
        return 1;
    }
}

int verify(void) {
    int dx, dy, tmp;
    if (rlen > n * n * 2) return 0;
    for (int i = 0; i < rlen; i++) {
        if (res[i][0] < 1 || res[i][1] < 1 || res[i][0] > n || res[i][1] > n) return 0;
        cnt[res[i][0]][res[i][1]]++;
        if (i == 0) continue;
        dx = res[i][0] - res[i - 1][0];
        dy = res[i][1] - res[i - 1][1];
        tmp = 0;
        for (int j = 0; j < 8; j++) {
            if (dx == dxy[j][0] && dy == dxy[j][1]) {
                tmp = 1;
                break;
            }
        }
        if (!tmp) return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cnt[i][j] == 0) return 0;
        }
    }
    return 1;
}

int main(void) {
    int rowp = 0, colp = 0, dirlr = 0, dirud = 0, ok = 1, x = 1, y = 1;
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    res[0][0] = x, res[0][1] = y;
    if (n < 4) {
        if (n == 1) printf("1\n1 1");
        else printf("-1");
        return 0;
    }
    while (x > 2 || y > 2) {
        if (rlen > n * 2) return 12;
        ok = moveknight(&x, &y, 5);
        if (!ok) {
            ok = moveknight(&x, &y, 6);
            if (!ok) {
                ok = moveknight(&x, &y, 2);
                if (!ok) return 11;
            }
        }
    }
    if (x == 2 && y == 2) {
        ok = moveknight(&x, &y, 0);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 5);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 2);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 5);
        if (!ok) return 12;
    }
    else if (x == 2 && y == 1) {
        ok = moveknight(&x, &y, 7);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 2);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 5);
        if (!ok) return 12;
    }
    else if (x == 1 && y == 2) {
        ok = moveknight(&x, &y, 0);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 3);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 5);
        if (!ok) return 12;
    }
    else if (x == 1 && y == 1);
    else return 12;
    if (x != 1 || y != 1) return 12;

    while (rowp < 2) {
        if (colp) {
            if (dirlr) {
                if (dirud) ok = moveknight(&x, &y, 5);
                else ok = moveknight(&x, &y, 2);
                if (!ok) {
                    if (dirud) {
                        ok = moveknight(&x, &y, 6);
                        if (!ok) return 1;
                        ok = moveknight(&x, &y, 5);
                        if (!ok) {
                            ok = moveknight(&x, &y, 1);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 3);
                            if (!ok) return 1;
                            dirlr = 0;
                            dirud = 1;
                            rowp++;
                            colp = 0;
                            continue;
                        }
                        ok = moveknight(&x, &y, 6);
                        dirlr = 0;
                        dirud = 0;
                    }
                    else {
                        ok = moveknight(&x, &y, 6);
                        if (!ok) break;
                        ok = moveknight(&x, &y, 5);
                        dirlr = 0;
                        dirud = 0;
                    }
                }
                else dirud = (!dirud);
            }
            else {
                if (dirud) ok = moveknight(&x, &y, 6);
                else ok = moveknight(&x, &y, 1);
                if (!ok) {
                    if (dirud) {
                        ok = moveknight(&x, &y, 5);
                        if (!ok) return 1;
                        ok = moveknight(&x, &y, 6);
                        if (!ok) return 2;
                        ok = moveknight(&x, &y, 5);
                        dirlr = 1;
                        dirud = 0;
                    }
                    else {
                        ok = moveknight(&x, &y, 5);
                        if (!ok) return 2;
                        ok = moveknight(&x, &y, 6);
                        dirlr = 1;
                        dirud = 0;
                    }
                }
                else dirud = (!dirud);
            }
        }
        else {
            if (dirlr) {
                if (dirud) ok = moveknight(&x, &y, 5);
                else ok = moveknight(&x, &y, 2);
                if (!ok) {
                    if (dirud) {
                        ok = moveknight(&x, &y, 1);
                        if (!ok) {
                            ok = moveknight(&x, &y, 7);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 4);
                            if (!ok) return 1;
                            dirlr = 0;
                            dirud = 0;
                            colp = 1;
                            continue;
                        }
                        ok = moveknight(&x, &y, 2);
                        dirlr = 0;
                        dirud = 1;
                    }
                    else {
                        ok = moveknight(&x, &y, 1);
                        if (!ok) return 1;
                        ok = moveknight(&x, &y, 2);
                        if (!ok) {
                            ok = moveknight(&x, &y, 7);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 4);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 2);
                            if (!ok) return 1;
                            dirlr = 0;
                            dirud = 1;
                            colp = 1;
                            continue;
                        }
                        ok = moveknight(&x, &y, 1);
                        dirlr = 0;
                        dirud = 1;
                    }
                }
                else dirud = (!dirud);
            }
            else {
                if (dirud) ok = moveknight(&x, &y, 6);
                else ok = moveknight(&x, &y, 1);
                if (!ok) {
                    if (dirud) {
                        ok = moveknight(&x, &y, 2);
                        if (!ok) {
                            ok = moveknight(&x, &y, 4);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 7);
                            if (!ok) return 1;
                            dirlr = 1;
                            dirud = 0;
                            colp = 1;
                            continue;
                        }
                        ok = moveknight(&x, &y, 1);
                        dirlr = 1;
                        dirud = 1;
                    }
                    else {
                        ok = moveknight(&x, &y, 2);
                        if (!ok) return 1;
                        ok = moveknight(&x, &y, 1);
                        if (!ok) {
                            ok = moveknight(&x, &y, 4);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 7);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 1);
                            if (!ok) return 1;
                            dirlr = 1;
                            dirud = 1;
                            colp = 1;
                            continue;
                        }
                        ok = moveknight(&x, &y, 2);
                        dirlr = 1;
                        dirud = 1;
                    }
                }
                else dirud = (!dirud);
            }
        }
    }

    if (!verify()) return -1;

    printf("%d\n", rlen);
    for (int i = 0; i < rlen; i++) {
        //printf("%d %d\n", res[i][0], res[i][1]);
    }
    return 0;
}