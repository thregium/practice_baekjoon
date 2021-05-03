#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : L(L <= 10^6)������ �Ÿ��� �̵��ϴµ� ���ô� 1���͸� rb�ʿ� �̵� �����ϰ�, ���� 1���͸� rf�ʿ� �̵� �����ϴ�.(rb < rf <= 10^6)
�̶�, N(N <= 100000)���� ���Ͱ� �ְ�, �� ���ʹ� ������ �ູ�� ci(ci <= 10^6)�� �����Ѵ�.
���ð� �� ���Ϳ��� �� ���� �ູ���� ���� �ð� * �� ������ �ູ���� ����. ���ð� ������ ��ó���� �ʾƾ� �� ��, ���ð� ���� �� �ִ� �ִ� �ູ���� ���Ѵ�.

�ذ� ��� : ���ô� ���� �ູ���� ���� ���Ϳ��� �ִ��� ���� ���� ���� ����. ����, ��� ���͵��� �ູ�� ������ �����Ѵ�.
�� ����, �� �պ��� ������ ���� ��ġ���� �ش� ���Ϳ��� �ִ��� ������ ���� �ູ���� �߰��ϰ�,
�������ʹ� �� ��ġ ���Ŀ� �ִ� ���� ��� �ູ���� ���� ���� ���͸� �����Ѵ�. �̸� �ݺ��ϸ� ��� ���Ϳ��� ������ ���� ���� �ִ����� �ູ���� ���� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : USACO 2018F S1��
*/

int rest[103000][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("reststops.in", "r");
        fo = fopen("reststops.out", "w");
    }
    int l, n, rf, rb, last = 0;
    long long result = 0;
    scanf("%d %d %d %d", &l, &n, &rf, &rb);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &rest[i][1], &rest[i][0]);
    }
    qsort(rest, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (rest[i][1] > last) {
            result += (rest[i][1] - last) * (long long)rest[i][0] * (rf - rb);
            last = rest[i][1];
        }
    }
    printf("%lld", result);
    return 0;
}