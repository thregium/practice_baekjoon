#include <stdio.h>

/*
���� : �־��� �� ��ǥ (N, M)�� �������� �� �� (X, Y)�� ��� ��и鿡 ���ϴ��� �Ǵ� ��輱�� �ִ��� ���Ѵ�.

�ذ� ��� : X, Y��ǥ�� N, M�� ���� ������� ��ġ�� ���� �� ��и��� ã���� �ȴ�.

�ֿ� �˰��� : ����

��ó : Brasil 2008 H��
*/

int main(void) {
    int k, n, m, x, y;
    while (1) {
        scanf("%d", &k);
        if (k == 0) break;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < k; i++) {
            scanf("%d %d", &x, &y);
            if (x == n || y == m) printf("divisa\n");
            else if (x < n && y < m) printf("SO\n");
            else if (x < n) printf("NO\n");
            else if (y < m) printf("SE\n");
            else printf("NE\n");
        }
    }
    return 0;
}