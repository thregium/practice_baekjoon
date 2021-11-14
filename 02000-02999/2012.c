#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 500000)���� ���� ����� �־��� ��, �� ����� ���� ����� ���� ����� ���� ���� �ּҷ� �Ѵٸ�,
�׶��� ���� ���Ѵ�. ��, �������� ���ͼ��� �� �ȴ�.

�ذ� ��� : ���� ��� ���� ������������ ������ ���� ���� ����� �״�� �ű�� ���� �����̴�.
�׶��� ���� ������� ���� ���� ���ϸ� �װ��� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����
*/

int a[524288];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        r += abs(a[i] - (i + 1));
    }
    printf("%lld", r);
    return 0;
}