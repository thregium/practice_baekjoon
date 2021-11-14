#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ����(|| <= 1000)�� �̷���� ������ �־��� ��, Q(Q <= 1000)���� ������ �����Ѵ�.
S, E ������ ���� ������ ���� ���� ��ȭ���� ���� ���Ѵ�.

�ذ� ��� : ��ȭ���� ���� ���ϴ��� �ð� ���� Ǯ �� �����Ƿ�, ��ȭ���� ���� ���ذ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : �߾Ӵ� 2019N C��
*/

int a[1024];

int main(void) {
    int n, q, s, e, r;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &s, &e);
        if (s >= e) printf("0\n");
        else {
            r = 0;
            for (int j = s; j < e; j++) {
                r += abs(a[j] - a[j + 1]);
            }
            printf("%d\n", r);
        }
    }
    return 0;
}