#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ī�� ��� L(1 <= L <= N)���� ������ �ڿ����� ���� ī��(<= 1000)�� �̾�
ī���� �� ���� �� ū ����� �̱�� ������ �ִ�. �� ���� ���� ī���� ��� ������ �־��� ��,
ù ��° ����� �׻� �� ��° ����� �̱� �� ���Ѵ�.

�ذ� ��� : �� ��° ������� �ּ��� ���� �� ��° ����� ���� ū ī�常 �̰�,
ù ��° ����� ���� ���� ī�常 �̴� ����̴�. �̸� ���ؼ��� �� ����� ī�带 ���� ��������,
������������ ������ ���� �տ������� L���� ī�带 �̰� ���� ���ϸ� �ȴ�.
ù ��° ����� ī�� ���� �� ũ�� ������ �����ϰ�, �ƴ϶�� �������� �ʴ� ���̴�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : RCC 2015Q1 A��
*/

int a[128], b[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, l, as, bs;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &l);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        qsort(b, n, sizeof(int), cmp2);
        as = 0, bs = 0;
        for (int i = 0; i < l; i++) {
            as += a[i];
            bs += b[i];
        }
        printf("%s\n", as > bs ? "YES" : "NO");
    }
    return 0;
}