#include <stdio.h>
#define MAX 131072

/*
���� : N(N <= 100000)���� ���� �̷���� �迭�� �ִ�. �� �迭���� X��° ������ Y��° ������ ���� ���� ����
A��° ���� B�� �ٲٴ� ������ �����Ѵ�.

�ذ� ��� : ���׸�Ʈ Ʈ���� �̿��� �������� ���ϰ� ���� ������Ʈ�ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��
*/

long long seg[MAX * 2];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

long long sum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return sum(x, y, s, (s + e) >> 1, p << 1) + sum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
}

void update(int a, int b) {
    seg[a + MAX] = b;
    for (int i = (a + MAX) >> 1; i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, q, x, y, a, b;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &seg[i + MAX]);
    }
    for (int i = MAX - 1; i > 0; i--) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &x, &y, &a, &b);
        if (x > y) swap(&x, &y);
        printf("%lld\n", sum(x - 1, y - 1, 0, MAX - 1, 1));
        update(a - 1, b);
    }
    return 0;
}