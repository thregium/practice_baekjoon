#include <stdio.h>

/*
���� : �־��� �ڿ��� 5�� �� �ִ��� ã�´�.

�ذ� ��� : �ִ��� 0���� ���� ��, �ִ񰪺��� ū ���� ������ �ִ��� ���Ž��� ã���� �ȴ�.

�ֿ� �˰��� : ����

��ó : Khawa 2013 G��
*/

int main(void) {
    int t, x, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        r = 0;
        for (int i = 0; i < 5; i++) {
            scanf("%d", &x);
            if (x > r) r = x;
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}