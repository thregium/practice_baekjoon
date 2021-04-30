#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FOUT 1
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : 7������ ���� �̸���� �ҵ��� ������ ������ ��ϵ��� ���� ��, ������ ���� ���� �������� ���� �� ���
������ ���� ���� ������ ���� �̸��� ����Ѵ�. 1������ �ƴ϶�� Tie�� ����Ѵ�.

�ذ� ��� : �� ���� �̸��� �ϵ��ڵ��صΰ� �� ���� ����� ã�� �̸��� ��ġ�ϴ� ��ȣ�� ���� ���� ���귮�� �־��� ����ŭ ���δ�.
���� ������ ���� ������ ���� ������ �Ҹ� ã�� ����, �׺��� ���� ������ �ҵ� ��� ���� ���� ������ ���� ��ȣ�� ���� ã�´�.
�� ���� 1�� ��� ���� ��ȣ�� ���� �̸��� ����ϰ�, �ƴ� ��� Tie�� ����Ѵ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : USACO 2017J B1��
*/

char* names[7] = { "Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta" };
char buff[16];
int cnt[7];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("notlast.in", "r");
        fo = fopen("notlast.out", "w");
    }
    int n, x, y, z = 0, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", buff, &x);
        for (int j = 0; j < 7; j++) {
            if (!strcmp(buff, names[j])) {
                cnt[j] += x;
                break;
            }
        }
    }
    x = 12345;
    for (int i = 0; i < 7; i++) {
        if (cnt[i] < x) x = cnt[i];
    }
    y = 12345;
    for (int i = 0; i < 7; i++) {
        if (cnt[i] < y && cnt[i] > x) {
            y = cnt[i];
            z = i;
            c = 1;
        }
        else if (cnt[i] == y) c++;
    }
    if (c == 1) printf("%s\n", names[z]);
    else printf("%s", "Tie");
    return 0;
}