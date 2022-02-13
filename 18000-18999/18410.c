#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� �����ϴ� 2000 ������ �ڿ����� �̷���� ���� N(N <= 500)�� �迭 A��
���� ������ ���� M(M <= 500)�� �迭 B�� �־��� ��, �� �迭�� ������ �־��� �˰����� ��ģ ����� ���Ѵ�.

�ذ� ��� : �־��� �˰����� �� �迭�� �������� �����ϸ� ��ġ�� ������ ����,
����, �� �迭�� ��ģ ���� ������ ����� ���� �ȴ�. �׷��Ƿ� �� �迭�� ��ġ�� �����ص� ���� �� �� �ִ�.

�ֿ� �˰��� : ����, ����

��ó : JOI 2020��1 1-3��
*/

int c[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; i++) {
        scanf("%d", &c[i]);
    }
    qsort(c, n + m, sizeof(int), cmp1);
    for (int i = 0; i < n + m; i++) {
        printf("%d\n", c[i]);
    }
    return 0;
}