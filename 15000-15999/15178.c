#include <stdio.h>

/*
���� : �־��� �� ���� ���� 180���� ���Ѵ�.

�ذ� ��� : �� ���� ���� 180���� Ȯ���غ��� �ȴ�.

�ֿ� �˰��� : ����?

��ó : NZPC 2017 A��
*/

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a + b + c == 180) printf("%d %d %d Seems OK\n", a, b, c);
        else printf("%d %d %d Check\n", a, b, c);
    }
    return 0;
}