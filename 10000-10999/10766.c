#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 4000)���� ���� �ִ�. �� ���� �Ÿ��� ���� ũ�⺸�� �۴ٸ� �� ���� �μ� �� �ְ�, �̴� ��� �ݺ��� �� �ִ�.
�̶�, ������ Ż���� �� ���� ������ ���̸� ���Ѵ�. ���� ��ġ�� 0 �̻� 10^9 ������ �����̴�.

�ذ� ��� : ��� ���� �ֿ� ���� �μ� �� �ִ� ������ Ȯ���Ѵ�. �μ� �� ���ٸ� ������ ��� ������ ����Ѵ�.
�� ������ ���� �μ� �� �ִ� ���� ���� �ָ� Ȯ���ؾ� �ð� ���� ���� ���� �����ϴ�.
����� �������� �ʺ� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : USACO 2015O B3��
*/

int hay[4096][2], itv[4096];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("trapped.in", "r");
        fo = fopen("trapped.out", "w");
    }
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &hay[i][1], &hay[i][0]);
    }
    qsort(hay, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (hay[i][1] >= (hay[j][0] - hay[i][0]) && hay[j][1] >= (hay[j][0] - hay[i][0])) {
                for (int k = i; k < j; k++) {
                    itv[k] = 1;
                }
                break;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (itv[i]) r += (hay[i + 1][0] - hay[i][0]);
    }
    printf("%d", r);
    return 0;
}