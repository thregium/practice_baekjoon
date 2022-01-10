#include <stdio.h>

/*
���� : N(N <= 20)���� ������ M(M <= 30)���� �̵� ���(�������� �������� �ڿ��� ĭ��ŭ �̵�)�� �־��� ��,
�κ��� (10, 10)���� ��� �̵� ����� �����ϸ� ��� ������ ���� �� �ִ� �� ���Ѵ�.
�̵� �߰����� ������ ���� �� �ִ�. ��� �������� (0, 0)�� (20, 20) �̳��� ���簢�� ���� �ȿ� ������,
�κ��� ��� �̵��� �ش� ���� �������� �̷������.

�ذ� ��� : �κ��� �̵��� �ùķ��̼��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : JDC 2006 A��
*/

int gem[32][2], earn[32];
int dxy[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int main(void) {
    int n, m, x, y, mov, dir = -1, res;
    char c;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &gem[i][0], &gem[i][1]);
            earn[i] = 0;
        }
        x = 10, y = 10;

        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf(" %c %d", &c, &mov);
            if (c == 'N') dir = 0;
            else if (c == 'E') dir = 1;
            else if (c == 'W') dir = 2;
            else if (c == 'S') dir = 3;
            else return 1;

            for (int j = 0; j < mov; j++) {
                x += dxy[dir][0];
                y += dxy[dir][1];
                for (int k = 0; k < n; k++) {
                    if (gem[k][0] == x && gem[k][1] == y) earn[k] = 1;
                }
            }
        }

        res = 1;
        for (int i = 0; i < n; i++) {
            if (!earn[i]) res = 0;
        }
        printf("%s\n", res ? "Yes" : "No");
    }
    return 0;
}