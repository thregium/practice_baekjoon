#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 150)���� ���ڿ�(<=200��, �ҹ���)�� �־��� ��, ª�� �� -> ���������� �����Ͽ� ����Ѵ�.

�ذ� ��� : ����ü�� ���� �Լ��� ����� �����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : JPOI 2007 1-2��
*/

typedef struct gem {
    int len;
    char s[256];
} gem;

gem g[192];

int cmp1(const void* a, const void* b) {
    gem ai = *(gem*)a;
    gem bi = *(gem*)b;
    return ai.len > bi.len ? 1 : ai.len == bi.len ? strcmp(ai.s, bi.s) : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", g[i].s);
        g[i].len = strlen(g[i].s);
    }
    qsort(g, n, sizeof(gem), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%s\n", g[i].s);
    }
    return 0;
}