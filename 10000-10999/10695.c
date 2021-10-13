#include <stdio.h>

/*
���� : N * N(N <= 10^9) ũ���� ü���ǿ��� (R1, C1)���� (R2, C2)�� ����Ʈ�� �� ���� �̵� �������� ���Ѵ�.
�� ĭ�� ��� ü���� �ȿ� �ִ�.

�ذ� ��� : �� ��ǥ�� ���̸� ���� ����, �� �����δ� ������ 1�̰� �ٸ� �����δ� ������ 2���� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : Tunisia 2013 G��
*/

int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };

int main(void) {
    int t, n, r1, c1, r2, c2, x, y, res;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d %d %d", &n, &r1, &c1, &r2, &c2);
        x = r1 - r2;
        y = c1 - c2;
        res = 0;
        for (int i = 0; i < 8; i++) {
            if (x == dxy[i][0] && y == dxy[i][1]) res = 1;
        }
        printf("Case %d: ", tt);
        if (res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}