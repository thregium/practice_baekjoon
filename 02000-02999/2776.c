#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10^6)���� ���� �־����� �ٽ� M(M <= 10^6)���� ���� �־��� ��, ���Ŀ� �־��� ������
������ �־��� ���� ��� �־����� ���� ���Ѵ�.

�ذ� ��� : ���� N���� ������ ������ ���� M���� ������ ���� �� ���� �̺� Ž���� ���� ������ �����ϴ��� ���Ѵ�.

�ֿ� �˰��� : ����, �̺� Ž��
*/

int exist[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, m, x;
    char* r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &exist[i]);
        }
        qsort(exist, n, sizeof(int), cmp1);
        scanf("%d", &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            r = bsearch(&x, exist, n, sizeof(int), cmp1);
            printf("%d\n", r == NULL ? 0 : 1);
        }
    }
    return 0;
}