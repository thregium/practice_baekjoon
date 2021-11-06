#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ���� �ϴ� ���� ���Ǵ� �ڿ� ���� �ּڰ��� ���Ѵ�. �� �ϵ��� �����ϱ� ������
�ڿ��� �ð��� D_i(D_i <= 100)��ŭ �Ҹ��ϸ�, �ҿ� �ð��� T_i(T_i <= 10^6)�̴�.

�ذ� ��� : �� ���� ������ �ٲ㰡�� Ȯ���غ��� T_i / D_i�� ���� ���� ���� ���� ���� �� ������ �� �� �ִ�.
����, �� ������ ��� ��°�� �ֵ� �� ���谡 �����Ǳ� ������ ������ ����� �� �ִ�.
�� ���� �������� ������ ����, ���Ǵ� �ڿ��� ���� ����ϸ� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : USACO 2007J S1��
*/

int cow[103000][2];
long long correct = 1234567890987654321;

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int bx = *(int*)b;
    int ay = *((int*)a + 1);
    int by = *((int*)b + 1);
    if (ax == 0 && ay == 0) ay = 1;
    if (bx == 0 && by == 0) by = 1;
    int r = ax * by - ay * bx;
    return r;
}
int main(void) {
    int n;
    long long r = 0, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cow[i][0], &cow[i][1]);
    }
    qsort(cow, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        r += cow[i][1] * s * 2;
        s += cow[i][0];
    }
    printf("%lld", r);
    return 0;
}