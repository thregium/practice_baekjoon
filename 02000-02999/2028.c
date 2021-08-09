#include <stdio.h>

/*
���� : N(N <= 1000) ������ ���� �־��� ��, �� ���� ������ �� �� �ڸ��� �� ���� ������ ���Ѵ�.

�ذ� ��� : N�� �ڸ������� ��츦 ������ �� ���� �������� ������ �ڸ����� ������ Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : Seoul 2006I B��
*/

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        if (n >= 100 && n * n % 1000 == n) printf("YES\n");
        else if (n < 100 && n >= 10 && n * n % 100 == n) printf("YES\n");
        else if (n < 10 && n * n % 10 == n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}