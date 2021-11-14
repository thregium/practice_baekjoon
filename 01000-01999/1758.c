#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ������ ���� ���� �־�����. �� ����� ������ �ִ� ���� ������ �� - (���� ���� - 1)�̴�.
��, ������ ��쿡�� 0���� ó���Ѵ�. �̶�, ���� �� �ִ� �ִ� ���� ���Ѵ�.

�ذ� ��� : ���� ���� ������ ����� �ʰ� �ִ��� ���� ���� �ʱ� ������ �ʰ� �ִ� ���� �̵��̴�.
����, ���� ������ �翡 ���� ������������ ������ �� ���� �� �ִ� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����
*/

int t[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, tip;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    qsort(t, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        tip = t[i] - i;
        if (tip > 0) r += tip;
    }
    printf("%lld", r);
    return 0;
}