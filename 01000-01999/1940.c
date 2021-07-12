#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 15000)���� ���� �ٸ� �ڿ����� �־��� ��, ���� M(M <= 10^7)�� �Ǵ� ���� ������ ���Ѵ�. �� ���� 100000 �����̴�.

�ذ� ��� : ������ ������ �� ���� ���������� ������ Ȯ���� ������. ���� �� ���� ���� M�� ���ٸ� �ᱣ���� 1 �ø� ����
Ȯ���� ��ġ�� �������� 1ĭ�� ��ܿ���, M���� ũ�ٸ� ������ ����, �۴ٸ� ���� ���� 1ĭ ��ܿ´�.
���� �� ��ġ�� ��ġ�ų� ������ ��� Ž���� �����ϰ� �ᱣ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �� ������
*/

int a[15360];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, lt, rt, res = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    lt = 0;
    rt = n - 1;
    while (lt < rt) {
        if (a[lt] + a[rt] == m) {
            lt++;
            rt--;
            res++;
        }
        else if (a[lt] + a[rt] < m) lt++;
        else rt--;
    }
    printf("%d", res);
    return 0;
}