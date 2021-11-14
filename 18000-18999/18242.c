#include <stdio.h>
#define INF 1012345678

/*
���� : N * M(N, M <= 100) ũ���� �迭�� '.'�� '#'���� �̷���� ���°� �ִ�. '#'�� �÷� �˻��� ���·� �Ǿ� �ִٸ�
�� ĭ�� �ִ� ������ ���Ѵ�.

�ذ� ��� : '#'�� �ִ� ��ǥ ��� X�� Y��ǥ�� �ִ�, �ּڰ��� ���Ѵ�. �� ����, ���� �Ǵ� ���� ������ ã��
�� ���� ��� �ٿ� �ִ����� Ȯ���� ������ ���Ѵ�.

�ֿ� �˰��� : ����, �ֵ� Ȥ

��ó : �Ѿ��E 2019Z E��
*/

char s[128][128];

int main(void) {
    int n, m, xl = INF, yl = INF, xh = -1, yh = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                if (i < xl) xl = i;
                if (i > xh) xh = i;
                if (j < yl) yl = j;
                if (j > yl) yh = j;
            }
        }
    }
    if (xh < 0) return 1;
    for (int i = 0; i < m - 2; i++) {
        if (s[xl][i] == '#' && s[xl][i + 1] == '.' && s[xl][i + 2] == '#') printf("UP");
        if (s[xh][i] == '#' && s[xh][i + 1] == '.' && s[xh][i + 2] == '#') printf("DOWN");
    }
    for (int i = 0; i < n - 2; i++) {
        if (s[i][yl] == '#' && s[i + 1][yl] == '.' && s[i + 2][yl] == '#') printf("LEFT");
        if (s[i][yh] == '#' && s[i + 1][yh] == '.' && s[i + 2][yh] == '#') printf("RIGHT");
    }
    return 0;
}