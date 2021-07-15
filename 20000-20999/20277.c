#include <stdio.h>

/*
���� : 10 * 10 ũ���� ���忡 ������ ������ ������ ��ġ�� ����, ���̰� �־�����. �̶� �� ������ ���� ����ų� ��ġ�� �ʰ�
�� �����ִ��� ���θ� ���Ѵ�.

�ذ� ��� : �� ������ ���� �ǿ� ���ƺ���. �ǿ��� ����ų� �̹� �ٸ� ���� �ִ� ��� ����� ���� ���� ���� ���̰�,
�׷��� �ʰ� ��� ���� ���� �� �ִٸ� ����� ���� �ִ� ���̴�.

�ֿ� �˰��� : ����

��ó : Brasil 2020 B��
*/

int field[16][16];

int main(void) {
    int n, d, l, r, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &d, &l, &r, &c);
        if (d) {
            for (int j = 0; j < l; j++) {
                if (r + j > 10 || field[r + j][c]) {
                    printf("N");
                    return 0;
                }
                field[r + j][c] = 1;
            }
        }
        else {
            for (int j = 0; j < l; j++) {
                if (c + j > 10 || field[r][c + j]) {
                    printf("N");
                    return 0;
                }
                field[r][c + j] = 1;
            }
        }
    }
    printf("Y");
    return 0;
}