#include <stdio.h>
#include <stdlib.h>

/*
���� : ī�� N(N <= 1000)���� �ְ�, �� ī����� ���̸� �� ī���� �հ� ���� ������ ���, �� �� �ϳ��� ���� �ٲ��.
�̶�, ���� �� �ִ� �ִ� ������ ���Ѵ�.

�ذ� ��� : �� ī����� ���� ���� ���� ���� ī��� ���̴� ���� �����̴�. ���� ū ���� �ٸ� ���� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : ���Ǵ� 2016 G��
*/

int l[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    qsort(l, n, sizeof(int), cmp1);
    for (int i = 1; i < n; i++) {
        r += l[0] + l[i];
    }
    printf("%lld", r);
    return 0;
}