#include <stdio.h>

/*
���� : R * C(R, C <= 50) ũ���� ���带 ����Ѵ�. �� ���� �� ĭ�� �������̸�, ����� �������� ������׷� ��Ÿ���� �Ѵ�.
�� ����, �������� ���̴� V, H���� ���� ���� �־�����.

�ذ� ��� : �������� �־������ �����Ѵ�.

�ֿ� �˰��� : ����

��ó : PacNW 2019 N��
*/

int vs[64], hs[64];

int main(void) {
    int r, c, v, h;
    scanf("%d %d %d %d", &r, &c, &v, &h);
    for (int i = 0; i < v; i++) {
        scanf("%d", &vs[i]);
    }
    for (int i = 0; i < h; i++) {
        scanf("%d", &hs[i]);
    }
    for (int i = 0; i < v; i++) {
        for (int ii = 0; ii < vs[i]; ii++) {
            for (int j = 0; j < h; j++) {
                for (int jj = 0; jj < hs[j]; jj++) {
                    printf("%c", ((i + j) & 1) ? 'W' : 'B');
                }
            }
            printf("\n");
        }
    }
    return 0;
}