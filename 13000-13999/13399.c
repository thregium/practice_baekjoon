#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� N(N <= 200000)�� 1 ~ N������ �ڿ����� ���ʷ� �־��� �迭�� �־��� ��, �迭�� Ư�� ���� �� ������ �ű��
������ M(M <= 100000)ȸ �Ѵٸ� ������ �迭�� ����Ѵ�.

�ذ� ��� : ���� ������ �迭�� ���� ����, Mȸ���� ������ ���鿡 ���� ���� �������� ���� ������ ������ �д�.
�� ����, ���� �������� ���� ����(��������, ������ �ʾҴٸ� 0) -> ������ ��(��������)�� �������� �����ϸ� �� �迭�� ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : Tsukuba 2016 A�� // Petro 2017W8 A��
*/

int a[204800][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int aj = *((int*)a + 1);
    int bj = *((int*)b + 1);
    if (aj != bj) return aj < bj ? 1 : -1;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, e;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) a[i][0] = i + 1;
    for (int i = 0; i < m; i++) {
        scanf("%d", &e);
        a[e - 1][1] = i + 1;
    }
    qsort(a, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i][0]);
    }
    return 0;
}