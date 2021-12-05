#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ������ ũ��� ������ ũ�Ⱑ ���� ��, �� ���ڿ� ���븦 1������ ������ ��� ���븦 ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : �� ���ڿ� ������ ũ�⸦ �����ϰ�, ������� ������Ų��. ���� ������ ũ�Ⱑ �� ū ��찡 ���´ٸ�
���� �� ���� ���밡 ������ ���̰�, ����, ��� ���븦 ���� �� ����. �� �ܿ��� ��� ���븦 ���� �� �ִ�.

�ֿ� �˰��� : ����, ����

��ó : COCI 17/18#5 1��
*/

int x[128], y[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }
    qsort(x, n, sizeof(int), cmp1);
    qsort(y, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (x[i] > y[i]) {
            printf("NE");
            return 0;
        }
    }
    printf("DA");
    return 0;
}