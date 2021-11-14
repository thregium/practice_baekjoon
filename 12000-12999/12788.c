#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���Լ� ���� ���� �� �ִ�. �� ������� ������ �� �ִ� ���� ��(<= 100)�� �־�����,
M * K(M * K <= 10000)���� ������ ���ؼ� ������ �ϴ� ����� �� �� �ּڰ��� ���Ѵ�. �Ұ����ϴٸ� "STRESS"�� ����Ѵ�.

�ذ� ��� : ���� ���� ���� ������� ������ �ȴ�. ���� ���� M * K�� �Ѿ ���� �� ������ ���� ��� ���� ����Ѵ�.
������ �Ѿ�� �ʴ´ٸ� STRESS�� ����Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : ���ϴ� 2016 K��
*/

int a[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, k, r = 0;
    scanf("%d%d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        r += a[i];
        if (r >= m * k) {
            printf("%d", i + 1);
            return 0;
        }
    }
    printf("STRESS");
    return 0;
}