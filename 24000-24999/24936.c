#include <stdio.h>
#include <stdlib.h>

/*
���� :N(N <= 100000)���� �ڿ���(<= 10000)�� �־�����. �̶�, �ڿ����� ��� �ϳ��� �� ���� ������ ������
���� ������ �� ������ ������������ ����Ѵ�.

�ذ� ��� : �켱 �� ���� ���� ���� ����, �� ������ �� �ڿ������� �� ���� �迭�� �����Ѵ�.
�̸� ������ ����, ���� ���� �ٸ� ���� ������ ���� �׷��� ���� �ٸ� ���� ������ ���ϰ�,
�ٽ� �� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : UAPC 2022 N��
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = s - a[i];
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i] != a[i + 1]) r++;
    }
    printf("%d\n", r);
    for (int i = 0; i < n; i++) {
        if (a[i] != a[i + 1]) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}