#include <stdio.h>
#define FOUT 0
#define INF 0x7A35090F
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 50000)���� ���� ��ǥ���� �ִ�. �� ���� ��� 1���� �����Ͽ� ���� �� �ִ� ��� ������ �����ϸ�
��ǥ�࿡ ������ ���� ���� ���簢���� ũ�� ��� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �� ������ �����Ͽ� ��ǥ�࿡ ������ ���� ���� ���簢���� ũ��� ��� ���� ���
(���� ū X��ǥ) - (���� ���� X��ǥ) * (���� ū Y��ǥ) - (���� ���� Y��ǥ)�̴�. �׷��� �� ���� ���� �����Ͽ� �� ��ǥ��
�� �� �ִ� �ĺ��� ���� ū/���� ���� �� ��°�� ū/���� �� �� ���̴�. ����, �� ������ ���� ������ ����,
N���� �� ������ ���� ���� �ش��ϴ� ���� ���� ū �� �Ǵ� ���� ���� ���� �ش��ϴ��� Ȯ���ϰ�,
�ش��Ѵٸ� �ش� ���� �� ��°�� ���� ������ �ٲٸ� �ش����� �ʴ� ���� ���� ū ������ ����Ͽ� ���簢���� ũ�⸦ ���Ѵ�.
�� ���簢���� ũ�� ��� �ּڰ��� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ������, ����

��ó : USACO 2016O B3��
*/

int pos[51200][2];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("reduce.in", "r");
        fo = fopen("reduce.out", "w");
    }

    int n, xh1 = 0, xh2 = 0, xl1 = INF, xl2 = INF, yh1 = 0, yh2 = 0, yl1 = INF, yl2 = INF, r = INF, xh, xl, yh, yl;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        if (pos[i][0] > xh1) {
            xh2 = xh1;
            xh1 = pos[i][0];
        }
        else if (pos[i][0] > xh2) xh2 = pos[i][0];
        if (pos[i][0] < xl1) {
            xl2 = xl1;
            xl1 = pos[i][0];
        }
        else if (pos[i][0] < xl2) xl2 = pos[i][0];
        if (pos[i][1] > yh1) {
            yh2 = yh1;
            yh1 = pos[i][1];
        }
        else if (pos[i][1] > yh2) yh2 = pos[i][1];
        if (pos[i][1] < yl1) {
            yl2 = yl1;
            yl1 = pos[i][1];
        }
        else if (pos[i][1] < yl2) yl2 = pos[i][1];
    }
    for (int i = 0; i < n; i++) {
        if (pos[i][0] == xh1) xh = xh2;
        else xh = xh1;
        if (pos[i][0] == xl1) xl = xl2;
        else xl = xl1;
        if (pos[i][1] == yh1) yh = yh2;
        else yh = yh1;
        if (pos[i][1] == yl1) yl = yl2;
        else yl = yl1;

        if ((xh - xl) * (yh - yl) < r) r = (xh - xl) * (yh - yl);
    }
    printf("%d", r);
    return 0;
}