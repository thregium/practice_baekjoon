#include <stdio.h>

/*
���� : W * L(W, L <= 20) ũ���� ���� �ִ�. ���� ����� '#'���� ���� ���� �ְ�, �� �� '*'����
�������� ���. �������� �ſ�(/, \)���� �ݻ�Ǿ� ������. �̶�, �������� ������ ĭ�� ��ġ�� ����Ѵ�.

�ذ� ��� : '*'�� �ִ� ĭ���� �ùķ��̼��� ���� �������� �̵����� ������ �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : MidC 2014 B��
*/

char house[32][32];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int w, l, x = -1, y = -1, d = -1;
    for (int tt = 1;; tt++) {
        scanf("%d %d", &w, &l);
        if (w == 0) break;
        for (int i = 0; i < l; i++) {
            scanf("%s", house[i]);
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                if (house[i][j] == '*') {
                    x = i, y = j;
                    if (j == 0) d = 0;
                    else if (i == 0) d = 1;
                    else if (j == w - 1) d = 2;
                    else if (i == l - 1) d = 3;
                    else return 1;
                }
            }
        }
        while (house[x][y] != 'x') {
            x += dxy[d][0];
            y += dxy[d][1];
            if (house[x][y] == '/') d = 3 - d;
            else if (house[x][y] == '\\') d ^= 1;
        }
        house[x][y] = '&';
        printf("HOUSE %d\n", tt);
        for (int i = 0; i < l; i++) {
            printf("%s\n", house[i]);
        }
    }
    return 0;
}