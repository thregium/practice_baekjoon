#include <stdio.h>
#include <stdlib.h>

/*
���� : N * N(N <= 9999) ũ���� ������ ���¿� ���� ���� ������ �����Ѵ�. �����̴� ���� ������ ����������
������������ �̵��Ѵ�.
1. N X Y�� �־��� ��, (X, Y)�� �ִ� ���� ����Ѵ�.
2. N X�� �־��� ��, X�� �ִ� ĭ�� ��ǥ�� ����Ѵ�.

�ذ� ��� : �������� �� ���� ���⿡ ���� ���� ó���Ѵ�.

�ֿ� �˰��� : ����, ����, ���̽� ��ũ
*/

int main(void) {
    int q, o, n, x, y, mid, base, res;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &o, &n, &x);
        mid = (n >> 1) + 1;
        if (o == 1) {
            scanf("%d", &y);
            base = abs(x - mid);
            if (abs(y - mid) > base) base = abs(y - mid);
            base = base * 2 - 1;
            if (base < 0) {
                printf("%d\n", n * n);
                continue;
            }
            res = n * n - base * base;
            if (x != y && y == mid - (base >> 1) - 1) {
                printf("%d\n", res - (x - (mid - (base >> 1))));
                continue;
            }
            else res -= base + 1;
            if (x == mid + (base >> 1) + 1) {
                printf("%d\n", res - (y - (mid - (base >> 1))));
                continue;
            }
            else res -= base + 1;
            if (y == mid + (base >> 1) + 1) {
                printf("%d\n", res - ((mid + (base >> 1)) - x));
                continue;
            }
            else res -= base + 1;
            if (x == mid - (base >> 1) - 1) {
                printf("%d\n", res - ((mid + (base >> 1)) - y));
                continue;
            }
            else return 3;
        }
        else if (o == 2) {
            x = n * n - x;
            for (base = 1; base * base <= x; base += 2);
            base -= 2;
            if (base < 0) {
                printf("%d %d\n", mid, mid);
                continue;
            }
            x -= base * base;
            if (x < base + 1) {
                printf("%d %d\n", mid - (base >> 1) + x, mid - (base >> 1) - 1);
                continue;
            }
            else x -= base + 1;
            if (x < base + 1) {
                printf("%d %d\n", mid + (base >> 1) + 1, mid - (base >> 1) + x);
                continue;
            }
            else x -= base + 1;
            if (x < base + 1) {
                printf("%d %d\n", mid + (base >> 1) - x, mid + (base >> 1) + 1);
                continue;
            }
            else x -= base + 1;
            if (x < base + 1) {
                printf("%d %d\n", mid - (base >> 1) - 1, mid + (base >> 1) - x);
                continue;
            }
            else return 2;
        }
        else return 1;
    }
    return 0;
}