#include <stdio.h>

/*
���� : �־��� �м��� ��м��� ��ģ��.

�ذ� ��� : �ڿ��� �κ��� ���� / �и��̰�, �м��� ���� �κ��� ���� % �и��̴�. ���� �κ��� 0�̶�� �ڿ����� ����ϰ�,
�ڿ��� �κ��� 0�̶�� �м��� ���, �� �ܿ��� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : UVa 2012 B��
*/

int main(void) {
    int t, n, d;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &d);
        printf("Case %d: ", tt);
        if (n % d == 0) printf("%d\n", n / d);
        else if (n / d == 0) printf("%d/%d\n", n, d);
        else printf("%d %d/%d\n", n / d, n % d, d);
    }
    return 0;
}