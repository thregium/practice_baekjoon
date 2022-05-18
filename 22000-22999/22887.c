#include <stdio.h>

/*
���� : N(N <= 100)���� �ڿ����� �̷���� ���� ��� reversesort�� ���(���� ũ���� ��)��
��Ȯ�� C(C <= 1000)�� ���� �ִ� �� ã�� �ִٸ� �׷��� ���� ����Ѵ�.

�ذ� ��� : ����� �ִ��� sum(2, ... N)�̰�, �ּڰ��� N - 1�̴�. �� ���� �ȿ� ���ٸ� �׷��� ������ ����.
�� ���� �ȿ� �ִٸ� ���ĵ� ���¿��� ������ ������ �ݺ��Ͽ� �׷��� ������ ã�� �� �ִ�.
�ִ񰪿��� C�� �� �� �� Ƚ����ŭ�� �ѱ�� �� Ƚ���� ���� ��ġ���� ������ ����,
�� ���ķ� �� ���������� ������ ������ ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : �ֵ� Ȥ?, ������, ����

��ó : GCJ 2021Q C��
*/

int a[128];

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void rev(int* a, int s, int e) {
    for (int i = s, j = e; i < j; i++, j--) {
        swap(&a[i], &a[j]);
    }
}

int main(void) {
    int t, n, c, mx;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &c);
        mx = 0;
        for (int i = 2; i <= n; i++) mx += i;
        if (c < n - 1 || c > mx) {
            printf("Case #%d: IMPOSSIBLE\n", tt);
            continue;
        }
        c = mx - c;
        for (int i = 1; i <= n; i++) a[i] = i;
        for (int i = n - 1; i > 0; i--) {
            for (int j = n; j > i; j--) {
                if (c == 0) {
                    rev(a, i, j);
                    break;
                }
                else c--;
            }
        }
        printf("Case #%d: ", tt);
        for (int i = 1; i <= n; i++) {
            printf("%d%c", a[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}