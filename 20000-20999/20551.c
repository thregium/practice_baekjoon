#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 200000)���� ����(|| <= 10^9)�� �̷���� �迭�� ������ �迭���� M(M <= 200000)���� ������ �����Ѵ�.
������ �迭���� D�� ó�� ������ ���� ������� ���Ѵ�. ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : ���� �迭�� ������ ���� �ߺ��� �����ϰ� ������ ù ��° ��ġ���� ���� �����Ѵ�.
�� ����, �� ������ ���� bsearch() �Լ��� �̿��� ������ ��ġ�� Ȯ���ϰ� �׿� �����ϴ� ù ��ġ�� ����ϸ� �ȴ�.
���� ���� ��� -1�� ����Ѵ�.

�ֿ� �˰��� : ����, �̺� Ž��

��ó : ���ϴ� 2020U B��
*/

int a[204800], a2[204800][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, sz = 0, x;
    int* p;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) continue;
        a2[sz][0] = a[i];
        a2[sz++][1] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        p = bsearch(&x, a2, sz, sizeof(int) * 2, cmp1);
        if (p == NULL) printf("-1\n");
        else printf("%d\n", *(p + 1));
    }
    return 0;
}