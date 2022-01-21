#include <stdio.h>

/*
���� : ������ �־��� �����ڵ带 ���� ������� ���� �˰��򿡼� K(K <= 10^8)��
��ȯ�� �Ͼ ���� �迭�� ����Ѵ�. �迭�� ũ��� N(N <= 10000)�̴�.
�� �迭�� ���Ҵ� 10^9 ������ �ڿ����̴�. K�� ��ȯ�� �Ͼ�� �ʴ´ٸ� -1�� ����Ѵ�.

�ذ� ��� : �־��� �����ڵ带 �ڵ�� ������ �� K�� ��ȯ�� �Ͼ�� ������ ���߰� �迭�� ����Ѵ�.
��, ���� �����ص� K�� ��ȯ�� �Ͼ�� �ʴ´ٸ� -1�� ����Ѵ�.

�ֿ� �˰��� : ����, ����
*/

int a[10240];
long long n, k;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int part(int s, int e) {
    int x = a[e];
    int i = s - 1;
    for (int j = s; j < e; j++) {
        if (a[j] <= x) {
            swap(&a[++i], &a[j]);
            if (--k <= 0) return 0;
        }
    }
    if (i + 1 != e) {
        swap(&a[i + 1], &a[e]);
        k--;
    }
    return i + 1;
}

void quick(int s, int e) {
    if (s < e) {
        int m = part(s, e);
        if (k <= 0) return;
        quick(s, m - 1);
        if (k <= 0) return;
        quick(m + 1, e);
        if (k <= 0) return;
    }
}

int main(void) {
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    quick(1, n);
    if (k) printf("-1");
    else {
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}