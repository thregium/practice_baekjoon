#include <stdio.h>

/*
���� : N(N <= 500000) ������ �ڿ���(<= 10^9)�� �̷���� �迭�� �ִ�. �� �迭�� ������ �־��� �����ڵ���
�� �����Ͽ��� ��, K(K <= 10^8)��° ��ȯ�� �Ͼ ���� �迭�� ����Ѵ�.
K�� ���Ϸ� ����ȴٸ� -1�� ����Ѵ�.

�ذ� ��� : ������ �־��� �����ڵ带 ������ ����, K������ ���� ��ȯ�� �� ����
��ȯ ���� Ƚ���� 1�� �ٿ�������. ��ȯ ���� Ƚ���� 0�� �Ǹ� ������ �����ϰ� �迭�� ����Ѵ�.
��ȯ ���� Ƚ���� ���� ��� -1�� ����Ѵ�.

�ֿ� �˰��� : ����, ����
*/

int a[524288];
int k;

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void hpf(int* a, int x, int n) {
    int lt = 2 * x, rt = 2 * x + 1, sml = 0;
    if (rt <= n) {
        if (a[lt] < a[rt]) sml = lt;
        else sml = rt;
    }
    else if (lt <= n) sml = lt;
    else return;

    if (a[sml] < a[x]) {
        swap(&a[x], &a[sml]);
        if (--k == 0) return;
        hpf(a, sml, n);
        if (k == 0) return;
    }
}

void build_mheap(int* a, int n) {
    for (int i = n >> 1; i >= 1; i--) {
        hpf(a, i, n);
        if (k == 0) return;
    }
}

void hsort(int* a, int s, int e) {
    build_mheap(a, e);
    if (k == 0) return;
    for (int i = e; i > s; i--) {
        swap(&a[s], &a[i]);
        if (--k == 0) return;
        hpf(a, s, i - 1);
        if (k == 0) return;
    }
}

int main(void) {
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    hsort(a, 1, n);
    if (k) printf("-1");
    else {
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}