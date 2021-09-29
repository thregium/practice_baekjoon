#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 50000)���� ���� 20 ������ ���ڿ����� �־�����. �̶�, �� ���ڿ����� ���� ������ ���� ���¶��
�� ���ڿ��� ���� ���������� ������ ���� ���� ������ ���� ���� ������ ���� ���Ѵ�.

�ذ� ��� : ��� ���ڿ����� ���� ������ ���� ���¶�� ���� ���� ������ ���� �ش� ���ڿ��� ������������ ���ĵǾ� �ְ�,
�ٸ� ���ڿ����� ������������ ���ĵǾ��� ���̴�. ���� ���� ������ ���� �翬�� �� �ݴ��� ����̴�.
�̵��� �˱� ���ؼ��� ��� ���ڿ����� �̸� ������������ ������ �迭�� ������������ ������ �迭���� ���� ����,
������ ���������� �����Ѵ�.
�� ����, �� ���ڿ��鿡 ���� ������������ ������ ����, �������� �迭���� �̺� Ž���� ���� �ش� ���� ���� ���� ������ ã��,
������������ ������ ���� �������� �迭���� �̺� Ž���� ���� �ش� ���� ���� ���� ������ ã�Ƽ�
������ ���� ���� ������ ���� ���� �������� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����, �̺� Ž��

��ó : USACO 2012D B2��
*/

char orig[51200][32], buff[32], lowest[51200][32], highest[51200][32];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("scramble.in", "r");
        fo = fopen("scramble.out", "w");
    }

    int n, l, h;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &orig[i]);
        strcpy(buff, orig[i]);
        qsort(buff, strlen(buff), sizeof(char), cmp1);
        strcpy(lowest[i], buff); //������������ ���ĵ� ���ڿ��� �迭
        qsort(buff, strlen(buff), sizeof(char), cmp2);
        strcpy(highest[i], buff); //������������ ���ĵ� ���ڿ��� �迭
    }
    qsort(lowest, n, sizeof(char) * 32, strcmp); //������ ���������� ������
    qsort(highest, n, sizeof(char) * 32, strcmp);

    for (int i = 0; i < n; i++) {
        strcpy(buff, orig[i]);
        qsort(buff, strlen(buff), sizeof(char), cmp1); //���� ������������ ������ �� ������������ ���ĵ� �迭������ ������ ����
        l = 0, h = n - 1;
        while (l < h) {
            if (strcmp(buff, highest[(l + h) >> 1]) > 0) l = ((l + h) >> 1) + 1;
            else h = ((l + h) >> 1);
        }
        printf("%d ", l + 1);
        qsort(buff, strlen(buff), sizeof(char), cmp2); //������������ ������ �� ������������ ���ĵ� �迭���� ������ ����
        l = 0, h = n - 1;
        while (l < h) {
            if (strcmp(buff, lowest[(l + h + 1) >> 1]) >= 0) l = ((l + h + 1) >> 1);
            else h = ((l + h + 1) >> 1) - 1;
        }
        printf("%d\n", l + 1);
    }
    return 0;
}