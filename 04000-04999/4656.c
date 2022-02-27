#include <stdio.h>

/*
���� : R(R <= 10) * C ũ���� �ȼ��� �� �׸��� N���� ���η� �־�����. �� ���� ���̴� 80 ���ϰ�,
�� �׸� ���̿��� ������ �־�����. �̶�, �� �׸��� 2�� ������ �ּ����� �ȼ��� ������ �� �ִ� �� ���ϰ�,
������ ��� �� �׸��� �����ϴ� �ȼ��� �ּ����� ������ ���� ����Ѵ�.
��, �׷��� ���� ���� ���� ��� ���� -> ���� �ִ� ���� �켱���� �Ѵ�.

�ذ� ��� : N, R, C�� ũ�Ⱑ ũ�� �ʱ� ������ ��� ����� ���� ���� ���ϴ� ���� �����ϴ�.
��, ������ ����� �����ϹǷ� �����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : MidC 2001 F��
*/

char px[64][16][96];

int main(void) {
    int n, r, c, res1, res2, res3;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2001\\double\\double.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2001\\double\\double_t.out", "w", stdout);
    for (int tt = 1;; tt++) {
        scanf("%d %d %d", &n, &r, &c);
        if (n == 0) break;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%s", px[j][i]);
            }
        }
        res1 = 1;
        for (int i = 0; i < n; i++) {
            res2 = 0;
            for (int x1 = 0; x1 < r; x1++) {
                for (int y1 = 0; y1 < c; y1++) {
                    if (px[i][x1][y1] == '.') continue;
                    res3 = 1;
                    for (int j = 0; j < n; j++) {
                        if (i == j) continue;
                        if (px[j][x1][y1] != '.') {
                            res3 = 0;
                            break;
                        }
                    }
                    if (!res3) continue;
                    px[i][x1][y1] = '#';
                    res2 = 1;
                    break;
                }
                if (res2) break;
            }
            if (res2) continue;
            for (int x1 = 0; x1 < r; x1++) {
                for (int y1 = 0; y1 < c; y1++) {
                    if (px[i][x1][y1] == '.') continue;
                    for (int x2 = 0; x2 < r; x2++) {
                        for (int y2 = 0; y2 < c; y2++) {
                            if (x1 == x2 && y1 == y2) continue;
                            if (px[i][x2][y2] == '.') continue;
                            res3 = 1;
                            for (int j = 0; j < n; j++) {
                                if (i == j) continue;
                                if (px[j][x1][y1] != '.' && px[j][x2][y2] != '.') {
                                    res3 = 0;
                                    break;
                                }
                            }
                            if (!res3) continue;
                            px[i][x1][y1] = '#';
                            px[i][x2][y2] = '#';
                            res2 = 1;
                            break;
                        }
                        if (res2) break;
                    }
                    if (res2) break;
                }
                if (res2) break;
            }
            if (res2 == 0) {
                res1 = 0;
                break;
            }
        }
        printf("Test %d\n", tt);
        if (res1 == 0) {
            printf("impossible\n");
            continue;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < n; j++) printf("%s%c", px[j][i], j == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}