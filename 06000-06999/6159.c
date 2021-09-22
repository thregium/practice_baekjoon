#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 20000)���� �ڿ����� �־��� ��, �� ���� ���� S(S <= 10^6) ������ ���� ������ ���Ѵ�.

�ذ� ��� : N���� �ڿ����� ������ ����, ���� ������ �����ؼ� ���� �ʿ������� ������ ���������� ���� S ���ϰ� �Ǵ�
������ ��ġ�� ���ϴ� ���ÿ� �ش� ������ �信 ���س����� �ȴ�.

�ֿ� �˰��� : ����, �� ������

��ó : USACO 2008J B1��
*/

int cows[20480];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s, r = 0, lo = 0, hi;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cows[i]);
    }
    hi = n - 1;
    qsort(cows, n, sizeof(int), cmp1);

    while (lo < hi) {
        while (cows[lo] + cows[hi] > s) hi--;
        r += ((hi - lo) > 0 ? (hi - lo) : 0);
        lo++;
    }
    printf("%d", r);
    return 0;
}