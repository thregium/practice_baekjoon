#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ����� �е�(<= 100000, �ڿ���)�� �� ����� ��(�ҹ���, 20��)�� �־�����.
�ٽ� M(M <= 100000)���� ���� �־��� ��, ���������� ������� �е� ������ ��Ű��
�� ����� ���ʷ� ���� �� �ִ� �� ���Ѵ�. �е��� ���� ���� �߰��� ������ �� �ȴ�.

�ذ� ��� : �� ��׵��� �е� ������� ������ ����, �־��� ������ �տ������� �������
ù ��° ���� ���� ���� ������� �����ϰ� �̸� �ݺ��ϸ� ��� ���� ���ʷ� ���� �� �ִ� �� Ȯ���ϸ� �ȴ�.
��, �е��� ���� ���� ������ �� �Ǳ� ������ �ֱ� ��װ� �е��� ���� ���� �Ѿ�� Ȯ���ؾ� �Ѵ�.

�ֿ� �˰��� : ����, �� ������

��ó : JAG 2018S3 B��
*/

typedef struct liq {
    int d;
    char c[24];
} liq;

char buff[32];
liq lq[103000];

int cmp1(const void* a, const void* b) {
    liq ai = *(liq*)a;
    liq bi = *(liq*)b;
    return ai.d > bi.d ? 1 : ai.d == bi.d ? 0 : -1;
}

int main(void) {
    int n, m, p = 0, last = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", lq[i].c, &lq[i].d);
    }
    qsort(lq, n, sizeof(liq), cmp1);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", buff);
        while (p < n && lq[p].d <= last) p++;
        while (p < n && strcmp(lq[p].c, buff)) p++;
        last = lq[p].d;
        if (p == n) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}