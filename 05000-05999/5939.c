#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 5000)���� �ð��� ��, ��, �� ������ �־��� ��, �ð��� ������������ ������ �־������ ����Ѵ�.

�ذ� ��� : �� �ð��� �� ������ �ٲٰ� ������ ��, ��, ��, �� ������ �ٽ� ��ȯ�Ͽ� ������� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : USACO 2010N B2��
*/

int times[5120];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, h, m, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &h, &m, &s);
        times[i] = h * 3600 + m * 60 + s;
    }
    qsort(times, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", times[i] / 3600, times[i] / 60 % 60, times[i] % 60);
    }
    return 0;
}