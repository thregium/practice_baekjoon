#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)�׷��� ������ �ɾ�� �ϴµ�, �Ϸ翡 �� �׷縸 ���� �� �ִ�.
�� ������ �ڶ�� �Ⱓ�� �־����� �ɱ� �����ؼ� ��� ������ �ڶ����� �ɸ��� �ð��� ���Ѵ�.

�ذ� ��� : �ڶ�µ� ���� �ɸ��� �������� �ɴ� ���� �����̴�.(���Ŀ� ������ �� ���� �ɸ� ���̹Ƿ�)
����, �Ⱓ�� �������� �������� ������ ����, ���� + �Ⱓ�� ���� �� ���� �ð��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : NCPC 2013 A��
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i + a[i] > r) r = i + a[i];
    }
    printf("%d", r + 2); //��¥ ����
    return 0;
}