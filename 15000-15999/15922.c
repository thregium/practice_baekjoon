#include <stdio.h>
#include <stdlib.h>

/*
���� : �������� N(N <= 100000)���� ���� �׾��� ��, ���� �������� ���̸� ���Ѵ�.

�ذ� ��� : ������ �������� �������� Ȯ���ϰ�, �������� ���� ���� ������ ������ 1 �ø���, ������ ���� 1 ���δ�.
���� ������ ������ 1 �̻��� ������ ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ������

��ó : ���� 2ȸ G��
*/

int lines[204800][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, ls = 0;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lines[i << 1][0], &lines[(i << 1) + 1][0]);
        lines[(i << 1) + 1][1] = 1;
    }
    qsort(lines, n * 2, sizeof(int) * 2, cmp1);
    for (int i = 0; i < (n << 1); i++) {
        if (i > 0 && ls > 0) r += lines[i][0] - lines[i - 1][0];
        if (lines[i][1] == 0) ls++;
        else ls--;
    }
    printf("%lld", r);
    return 0;
}