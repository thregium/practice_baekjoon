#include <stdio.h>

/*
���� : N(N <= 1000)�ϰ� A, B, C �� �ϳ��� �� �� ���� �� ���� ��, A, B, C�� ������ �� ��¥���� �־����ٸ�
���� �� �ִ� �ִ� ������ ���Ѵ�.

�ذ� ��� : ���� ������ ���� ū ���� ����. ���� �װ��� ������ 0 ���϶��, ������, �̻��� ��� �����´�.
�̸� �ݺ��� ������ ���� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : ���δ� 2016 D��
*/

int big3(int a, int b, int c) {
    if (a > b && a > c) return a;
    else if (b > c) return b;
    else return c;
}

int main(void) {
    int t, n, a, b, c, d, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &a, &b, &c);
            d = big3(a, b, c);
            if (d > 0) r += d;
        }
        printf("%d\n", r);
    }
    return 0;
}