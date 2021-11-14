#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� �ǹ��� �� �ǹ��� ���̰� �־��� ��, �ǹ��� ��� �μ��� ���� ��� �� �� ��� �ϴ��� ���Ѵ�.
��� �� �� ���� ��� �ǹ��� �� �� �μ��ų� �� �ǹ��� �μ� �� �ִ�.

�ذ� ��� : �ǹ��� ���� ������ ������ ��, �� �ǹ����� ������ �ν��� �� ��� ���� Ƚ���� �� ���鼭 ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : NCPC 2014 E��
*/

int h[103000];
int cnt[1048576];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main() {
    int n, x, p = 0, r;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (cnt[x] == 0) {
            h[p++] = x;
        }
        cnt[x]++;
    }
    qsort(h, p, sizeof(int), cmp1);

    r = n;
    x = 0;
    for (int i = 0; i < p; i++) {
        x += cnt[h[i]];
        r = small(r, h[i] + n - x);
    }
    printf("%d", r);
    return 0;
}