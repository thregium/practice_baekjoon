#include <stdio.h>

/*
���� : ��ǥ����� Ư���� �������� �ɾ ��, Ư���� ��ǥ�� �̵��� ���� �ִ��� Ȯ���ϰ� �ִٸ� �� ��°�� �̵��ߴ��� ���Ѵ�.
��ǥ�� ������ 0 �̻� 5000 ������ �����̴�.

�ذ� ��� : ������ �м��� ��츦 ������ �ذ��Ѵ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : Tehran 2000 A��
*/

int main(void) {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x == y) {
            if (x & 1) printf("%d\n", x * 2 - 1);
            else printf("%d\n", x * 2);
        }
        else if (x == y + 2) {
            if (x & 1) printf("%d\n", x + y - 1);
            else printf("%d\n", x + y);
        }
        else printf("No Number\n");
    }
    return 0;
}