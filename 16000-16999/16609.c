#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 200000)���� ����� �뷮(0<=, <= N)�� �־��� ��, �뷮�� 1���� N������ ǳ���� �Ͷ߸��� �ʰ�
����� ä���� �� ����� ������ ���� ���� ǳ���� ������ ���Ѵ�. �Ͷ߸��� �ʴ� ����� ���ٸ� impossible�� ����Ѵ�.
����� �뷮�� �Ѿ�� ������.

�ذ� ��� : ������� �뷮�� ���� �ͺ��� ������������ ������ ����, ǳ���� �뷮�� ���Ѵ�.
ǳ���� �뷮���� ū ���� �ִٸ� impossible�� ����ϰ�, �� �ܿ��� ����� ������ ã�Ƽ� ���� ���� ���� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : NWERC 2018 I��
*/

int c[103000 * 2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    double r = 1.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    qsort(c, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (c[i] > i + 1) r = -1.0;
        else if ((double)c[i] / (i + 1.0) < r) r = (double)c[i] / (i + 1.0);
    }
    if (r < 0) printf("impossible");
    else printf("%.9f", r);
    return 0;
}