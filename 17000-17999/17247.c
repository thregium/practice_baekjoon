#include <stdio.h>
#include <stdlib.h>

/*
���� : N * M(N, M <= 1000) ũ���� �迭�� '1'�� 2�� �ִ�. �� '1' ���� ����ư �Ÿ��� ���Ѵ�.

�ذ� ��� : �� '1'�� ��ġ�� ���� ����, �� ��ġ�� X��ǥ ���̿� Y��ǥ ���̸� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ������, ����

��ó : ���ϴ� 2019 D��
*/

int main(void) {
    int n, m, t, c = 0, x1 = -1, x2 = -1, y1 = -1, y2 = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &t);
            if (t) {
                c++;
                if (c == 1) {
                    x1 = i;
                    y1 = j;
                }
                else if (c == 2) {
                    x2 = i;
                    y2 = j;
                }
                else return 1;
            }
        }
    }
    if (c != 2) return 2;
    printf("%d", abs(x1 - x2) + abs(y1 - y2));
    return 0;
}