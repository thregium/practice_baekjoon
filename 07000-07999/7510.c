#include <stdio.h>

/*
���� : �ﰢ���� �� ���� ���̰� �־��� ��, �־��� �ﰢ���� �����ﰢ������ ���Ѵ�.

�ذ� ��� : ��Ÿ����� ������ ������ ���� �� ���� ������ ������ �ٸ� �� ���� ������ �հ� ���ٸ� �����ﰢ���̴�.

�ֿ� �˰��� : ������, ��Ÿ��� ����

��ó : TUD 2008 8��
*/

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int nn = 1; nn <= n; nn++) {
        scanf("%d %d %d", &a, &b, &c);
        printf("Scenario #%d:\n", nn);
        if (a > b && a > c) {
            if (a * a == b * b + c * c) printf("yes");
            else printf("no");
        }
        else if (b > a && b > c) {
            if (b * b == a * a + c * c) printf("yes");
            else printf("no");
        }
        else if (c > a && c > b) {
            if (c * c == a * a + b * b) printf("yes");
            else printf("no");
        }
        else printf("no");
        printf("\n\n");
    }
    return 0;
}