#include <stdio.h>

/*
���� : N(N <= 5000)���� ����(|| <= 10^9)�� ������ �����ִ�. �̶�, (X1, Y1), (X2, Y2) ������
���簢�� ���� �ȿ� ���� ������ ������ M(M <= 500000)�� ���Ѵ�. (�ð� ���� 5��)

�ذ� ��� : �ð� ������ �˳��ϱ� ������ ���Ʈ ������ Ǯ�� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : JAG 2012S2 C��
*/

int tres[5120][2];

int main(void) {
    int n, m, x1, y1, x2, y2, r;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tres[i][0], &tres[i][1]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        r = 0;
        for (int j = 0; j < n; j++) {
            r += (x1 <= tres[j][0] & tres[j][0] <= x2 & y1 <= tres[j][1] & tres[j][1] <= y2);
        }
        printf("%d\n", r);
    }
    return 0;
}