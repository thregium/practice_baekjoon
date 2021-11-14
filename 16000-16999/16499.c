#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� 10�� ������ �ҹ��ڷ� �� ���ڿ��� �־��� ��, ���� �Ƴ��׷� ������ �׷��� �� ������ ���Ѵ�.

�ذ� ��� : �� ���ڿ��� ������ ����, ��ü ���ڿ��� �����Ѵ�. �� ����, ������ ���ڿ����� ���� ���� ���ϰ�
������ ���ڿ��� ������ ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : �Ѿ��E 2018B A��
*/

char wd[128][16];

int cmp1(const void* a, const void* b) {
    int ai = *(char*)a;
    int bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", wd[i]);
        qsort(wd[i], strlen(wd[i]), sizeof(char), cmp1);
    }
    qsort(wd, n, sizeof(char) * 16, strcmp);
    for (int i = 0; i < n; i++) {
        if (i > 0 && !strcmp(wd[i], wd[i - 1])) continue;
        r++;
    }
    printf("%d", r);
    return 0;
}