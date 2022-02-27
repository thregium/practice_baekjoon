#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 100000)���� �ֹ��� �־�����. �̶�, �� �ֹ��� �� ���� ���� �ֹ��� ��ġ��,
�ֹ����� �̸��� ���� -> �̸��� ���������� �����Ͽ� ����� ����� ����Ѵ�.

�ذ� ��� : ������ ���Ǵ�� ������ ����, �ٸ� �ֹ��� ���� �� ����
�ֹ��� ���� ����� ����ϴ� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�, ����

��ó : JOI 2006��2 3��
*/

typedef struct prod {
    char name[8];
    long long cnt;
} prod;

prod p[1048576];

int cmp1(const void* a, const void* b) {
    prod ai = *(prod*)a;
    prod bi = *(prod*)b;
    if (strlen(ai.name) != strlen(bi.name)) return strlen(ai.name) > strlen(bi.name) ? 1 : -1;
    else return strcmp(ai.name, bi.name);
}

int main(void) {
    int n;
    long long c = 0;
    scanf("%d", &n);
    if (n > 1000000) return 1;
    for (int i = 0; i < n; i++) {
        scanf(" %s %d", p[i].name, &p[i].cnt);
    }
    qsort(p, n, sizeof(prod), cmp1);
    for (int i = 0; i < n; i++) {
        if (i > 0 && strcmp(p[i].name, p[i - 1].name)) {
            printf("%s %lld\n", p[i - 1].name, c);
            c = p[i].cnt;
        }
        else c += p[i].cnt;
    }
    printf("%s %lld\n", p[n - 1].name, c);
    return 0;
}