#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
���� : 150 * 150 ���� ũ���� ���簢�� ������ ���ڿ� ���� ��� �� ���� ���簢���� �̷��� �ʵ���
���� 1700�� �̻� �̴� ����� ����Ѵ�.

�ذ� ��� : ���� �缱���� ������ ������ ���簢���� �̷��� �ʰ� �ȴ�. �̸� ���� �� �缱���� ���ʷ� �̵�,
���簢���� �̷��� �ʵ��� ������ 1608���� ���� �� �ִ�. ���⿡ �ణ�� �������� �߰��ϸ� ��κ��� ���
�̺��� ���� �������� ������ �̺��� ���� ������ ������ �ȴ�. 1700�� �̻��� �Ǹ�
�׶��� �̴� ����� ����ϰ� �̸� �̿��ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ������, ������ȭ, ��ó��

��ó : Petro 2016S9 G��
*/

char res[256][256];

int main(void) {
    int n = 150, r = 0, sel, best, cnt, ok, rr = 0;
    for (int tt = 0;; tt++) {
        r = 0, rr = 0;
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) res[i][j] = '.';
        }
        while (r + rr < n * n) {
            sel = -1, best = -1;
            for (int i = 0; i < n * 2 - 1; i++) {
                cnt = 0;
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < n; jj++) {
                        if (ii + jj != i) continue;
                        if (res[ii][jj] != '.') ok = 0;
                        else cnt++;
                    }
                }
                if (cnt > best) {
                    if (rand() % 100 > 50) continue;
                    best = cnt;
                    sel = i;
                }
            }
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < n; jj++) {
                    if (ii + jj != sel) continue;
                    r++;
                    res[ii][jj] = 'O';
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int ii = i + 1; ii < n; ii++) {
                        for (int jj = j + 1; jj < n; jj++) {
                            if ((res[i][j] == 'O') + (res[i][jj] == 'O') + (res[ii][j] == 'O') + (res[ii][jj] == 'O') == 3) {
                                if (res[i][j] == '.') res[i][j] = '*';
                                else if (res[i][jj] == '.') res[i][jj] = '*';
                                else if (res[ii][j] == '.') res[ii][j] = '*';
                                else if (res[ii][jj] == '.') res[ii][jj] = '*';
                                else rr--;
                                rr++;
                            }
                        }
                    }
                }
            }
        }
        printf("%d %d\n", r, rr);
        if (r < 1660) continue;
        for (int i = 0; i < n; i++) {
            printf("%s\n", res[i]);
        }
        if (r >= 1700) break;
    }
    return 0;
}