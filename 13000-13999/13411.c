#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ���� �־��� ��, �������� �ӵ� v_i(v_i <= 1000)�� �ش� ������ �̵��Ѵٸ�
�����ϴ� ������� ������ ��ȣ�� ����Ѵ�. ���ÿ� �����ϴ� ��� ��ȣ�� ���� ���� �켱�̴�.

�ذ� ��� : �ش� �������� �̵� �ð��� ������ ���� ����, �̸� ���� �� �� -> ��ȣ ������ �����ϰ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ������, ����

��ó : ���δ� 2016 PB��
*/

int miss[103000][4];

long long sqr(long long x) {
    return x * x;
}

int cmp1(const void* a, const void* b) {
    long long ax = *(int*)a;
    long long bx = *(int*)b;
    long long ay = *((int*)a + 1);
    long long by = *((int*)b + 1);
    long long av = *((int*)a + 2);
    long long bv = *((int*)b + 2);
    int ai = *((int*)a + 3);
    int bi = *((int*)b + 3);
    long long aa = sqr(ax) + sqr(ay);
    aa *= sqr(bv);
    long long ba = sqr(bx) + sqr(by);
    ba *= sqr(av);
    if (aa != ba) return aa > ba ? 1 : -1;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &miss[i][0], &miss[i][1], &miss[i][2]);
        miss[i][3] = i + 1;
    }
    qsort(miss, n, sizeof(int) * 4, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d\n", miss[i][3]);
    }
    return 0;
}