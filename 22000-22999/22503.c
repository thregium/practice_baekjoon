#include <stdio.h>

/*
���� : M * N(M, N <= 500) ũ���� ĭ�� '.'��� �빮�ڵ��� �ִ�. �� �빮�ڵ��� ���ų� ��Ȯ�� 2�� �ִ�.
������ ĭ�� ������ �� ĭ�� �����¿�� ������ ù ���ڱ��� ���� �̾�����. �� ���ڵ� ���
���� ���� ���ڰ� �ִ� ��� ������ٰ� �Ѵ�. �̶�, ������� ���� �� �ִ� ������ �ִ� ������ ���Ѵ�.

�ذ� ��� : �� ���ڵ��� Ȯ���ϸ鼭 ������ ���ڸ� ���� �� �ִ� ĭ���� �߷�����.
�� ���ڰ� �������� �ִ� ��� �� ���� ������ ��ġ����, �� ���� ��쿡�� ���� �ݴ��� ������ ��ġ 2������
�� ���ڵ��� ���� �� �ֱ� ������ �� ĭ�鸸 ����� �ȴ�.
�� ����, �ش� ĭ���� ��� �������鼭 ���̻� ���ڰ� ������� ���� �� ���� �̸� �ݺ��ϸ� �ȴ�.
���ڰ� �ִ� ĭ�� �����ų� ������ ����� ��� � �����Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����?, ���̽� ��ũ

��ó : JAG 2011S2 J��
*/

char tile[512][512];
int pos[16384][2], look[4][2];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int m, n, x1, y1, x2, y2, p = 0, c, r = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s", tile[i]);
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        x1 = -1, y1 = -1, x2 = -1, y2 = -1, c = 0;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (tile[j][k] == i) {
                    if (c == 0) {
                        x1 = j, y1 = k;
                    }
                    else if (c == 1) {
                        x2 = j, y2 = k;
                    }
                    else return 1;
                    c++;
                }
            }
        }
        if (c != 0 && c != 2) return 1;
        if (c == 0) continue;
        if (x1 > x2) {
            swap(&x1, &x2);
            swap(&y1, &y2);
        }
        else if (x1 == x2 && y1 > y2) {
            swap(&x1, &x2);
            swap(&y1, &y2);
        }
        if (x1 < x2 && y1 != y2) {
            pos[p][0] = x1;
            pos[p++][1] = y2;
            pos[p][0] = x2;
            pos[p++][1] = y1;
        }
        else if (x1 == x2) {
            for (int i = y1 + 1; i < y2; i++) {
                pos[p][0] = x1;
                pos[p++][1] = i;
            }
        }
        else if (y1 == y2) {
            for (int i = x1 + 1; i < x2; i++) {
                pos[p][0] = i;
                pos[p++][1] = y1;
            }
        }
        else return 2;
    }

    c = 1;
    while (c) {
        c = 0;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0;; k++) {
                    x1 = pos[i][0] + dxy[j][0] * k;
                    y1 = pos[i][1] + dxy[j][1] * k;
                    if (x1 < 0 || y1 < 0 || x1 >= m || y1 >= n) {
                        look[j][0] = -1;
                        look[j][1] = -1;
                        break;
                    }
                    if (tile[x1][y1] != '.') {
                        look[j][0] = x1;
                        look[j][1] = y1;
                        break;
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
                if (look[i][0] < 0) continue;
                for (int j = i + 1; j < 4; j++) {
                    if (look[j][0] < 0) continue;
                    if (tile[look[i][0]][look[i][1]] != '.' && tile[look[i][0]][look[i][1]] ==
                        tile[look[j][0]][look[j][1]] && !(look[i][0] == look[j][0] &&
                            look[i][1] == look[j][1])) {
                        tile[look[i][0]][look[i][1]] = '.';
                        tile[look[j][0]][look[j][1]] = '.';
                        c += 2;
                        r += 2;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", r);
    return 0;
}