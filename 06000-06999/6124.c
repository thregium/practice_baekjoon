#include <stdio.h>

/*
���� : NR * NC(NR, NC <= 100) ũ���� ���ڿ��� 3 * 3 ũ�� ������ ���� ���� ū �� ��� �� -> �� ��ȣ�� ���� ���� ���� ���Ѵ�.
�ش��ϴ� �հ� ���� �� ĭ�� ��, �� ��ȣ�� ����Ѵ�.

�ذ� ��� : �� ������ �Է¹��� ����, ��� 3 * 3 ũ���� ������ ���ɴ�. �� -> ���� �����ϴ� ������ Ž���ϰ�,
�ִ񰪺��� ���� ū ���� �߰��ϸ� �ش��ϴ� ��, �� ��ȣ�� �����ϰ�, �ִ񰪵� �������ش�. �������� �ִ�, ��, �� ��ȣ�� ����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : USACO 2009O B3��
*/

int grass[128][128];

int main(void) {
    int nr, nc, s, best = 0, bx = -1, by = -1;
    scanf("%d %d", &nr, &nc);
    for (int i = 1; i <= nr; i++) {
        for (int j = 1; j <= nc; j++) {
            scanf("%d", &grass[i][j]);
        }
    }
    for (int i = 1; i < nr - 1; i++) {
        for (int j = 1; j < nc - 1; j++) {
            s = 0;
            for (int ii = 0; ii < 3; ii++) {
                for (int jj = 0; jj < 3; jj++) s += grass[i + ii][j + jj];
            }
            if (s > best) {
                best = s;
                bx = i;
                by = j;
            }
        }
    }
    if (bx < 0) return 1;
    printf("%d\n%d %d", best, bx, by);
    return 0;
}