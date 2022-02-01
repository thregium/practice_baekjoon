#include <stdio.h>

/*
���� : N(N <= 500000) ������ �ڿ���(<= 10^9)�� �̷���� �迭�� �ִ�. �� �迭�� ������ �־��� �����ڵ���
���� �����Ͽ��� ��, K(K <= 10^8)��°�� ����Ǵ� ���� ����Ѵ�. K�� ���Ϸ� ����ȴٸ� -1�� ����Ѵ�.

�ذ� ��� : ������ �־��� �����ڵ带 ������ ����, K������ ���� ����� �� ���� ���� Ƚ���� 1�� �ٿ�������.
���� Ƚ���� 0�� �Ǹ� ���������� ������ ���� Ȯ���� ���� ������ �����ϰ� �� ���� ����Ѵ�.
���� Ƚ���� ���� ��� -1�� ����Ѵ�.

�ֿ� �˰��� : ����, ����
*/

int a[524288], tmp[524288];
int k = 0, res;

void rest(int* a, int p, int r) {
    int i = p, t = 1;
    while (i <= r) a[i++] = tmp[t++];
}

void merge(int* a, int p, int q, int r) {
    int i = p, j = q + 1, t = 1;
    while (i <= q && j <= r) {
        if (a[i] <= a[j]) tmp[t++] = a[i++];
        else tmp[t++] = a[j++];
        if (--k == 0) {
            res = tmp[t - 1];
            return;
        }
    }
    while (i <= q) {
        tmp[t++] = a[i++];
        if (--k == 0) {
            res = tmp[t - 1];
            return;
        }
    }
    while (j <= r) {
        tmp[t++] = a[j++];
        if (--k == 0) {
            res = tmp[t - 1];
            return;
        }
    }
    rest(a, p, r);
}

void msort(int* a, int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) >> 1;
        msort(a, p, q);
        if (k == 0) return;
        msort(a, q + 1, r);
        if (k == 0) return;
        merge(a, p, q, r);
        if (k == 0) return;
    }
}

int main(void) {
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    msort(a, 1, n);
    if (k) printf("-1");
    else printf("%d", res);
    return 0;
}