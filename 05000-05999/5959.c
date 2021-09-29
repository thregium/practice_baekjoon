#include <stdio.h>

/*
���� : N(N <= 400)���� ���� �߽� ��ǥ�� �������� �־��� ��, �� ������ �� ���� ��ġ�� �ٸ� ���� ������ ���Ѵ�.

�ذ� ��� : �� ���� �߽� ��ǥ�� �Է¹��� ����, ��� �ٸ� ���� ���� �߽� ������ �Ÿ���
�������� �պ��� ���� ���� ������ ���ϸ� �ȴ�. �̴� ��Ÿ����� ������ �̿���
X��ǥ ������ ������ Y��ǥ ������ ������ �Ÿ��� �����̶�� ����� �˸� ������ Ǯ �� �ִ�.

�ֿ� �˰��� : ������, ���Ʈ ����

��ó : USACO 2011J B4��
*/

int circle[512][3];

int sqr(int x) {
    return x * x;
}

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &circle[i][0], &circle[i][1], &circle[i][2]);
    }
    for (int i = 0; i < n; i++) {
        r = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (sqr(circle[i][0] - circle[j][0]) + sqr(circle[i][1] - circle[j][1]) < sqr(circle[i][2] + circle[j][2])) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}