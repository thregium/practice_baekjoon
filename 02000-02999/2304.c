#include <stdio.h>

/*
���� : N(N <= 1000)���� ����� ��ġ�� ���̰� �־��� ��, â�� �ٰ����� ���̸� ���Ѵ�. â�� �ٰ�����, ������ ���� �κ�����
����� �ٰ����̰�, �� ����, ���� �κ��� ��հ� ��ƾ� �ϸ�, �������� ���� �ٰ����̴�.

�ذ� ��� : �̷��� â�� �ٰ����� �� ���������� ���̴� 1���� �� ���������� ���� ���� �ִ񰪰�, �ݴ� �������� ���� ����
�ִ� ��� �� ���� ���̴�. �̸� 1���� �������� �ݺ��Ͽ� ã�Ƴ��� �ȴ�.

�ֿ� �˰��� : ����?

��ó : ���� 2005 ��2��
*/

int a[1024], lbest[1024], rbest[1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, l, h, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &h);
        a[l] = h;
    }
    for (int i = 1; i <= 1000; i++) {
        if (a[i] > lbest[i - 1]) lbest[i] = a[i];
        else lbest[i] = lbest[i - 1];
    }
    for (int i = 1000; i > 0; i--) {
        if (a[i] > rbest[i + 1]) rbest[i] = a[i];
        else rbest[i] = rbest[i + 1];
    }
    for (int i = 1; i <= 1000; i++) {
        r += small(lbest[i], rbest[i]);
    }
    printf("%d", r);
    return 0;
}