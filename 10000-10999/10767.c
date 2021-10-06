#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N * N(N <= 18) ũ���� �ǿ� �빮�ڵ��� ���� �ִ�. ���� ���� �� ĭ���� ����Ͽ� ������ �Ǵ� �Ʒ������� �̵��ϸ�
���� ���ڿ��� �� �Ӹ������ ���� �������� ���Ѵ�. ��ΰ� �ٸ����� ���ڿ��� ���ٸ� ���� ���̴�.

�ذ� ��� : ���� ���� ������ ������ �Ʒ����� �̵��ϸ� �������� ����ġ�� �������Ƿ� �ð� �ʰ��� ���� ���̴�.
����, ��� ĭ(/������ �밢���� �ִ� ĭ)�鿡�� ����Ͽ� ���� �� ĭ�� ������ �Ʒ� ĭ���� �̵��Ѵ�.
�׷��� ���� �� �ִ� �������� ���ƾ� 2^17������ �Ұ��ϹǷ� �־��� ��쵵 �ذ� �����ϴ�.

�� �̵� �� �� �̵����� ���� ���ڿ����� ���� �����Ѵ�. �� ����, �̺� Ž���� �̿��� ù ��° �̵����� ����
���ڿ� ��� �� ��° �̵������� �����ϴ� ���ڿ����� ��� �迭�� �ű��.
�� ������ �� ��� ĭ�� ���� �ݺ��� ����, ��� �迭�� �����ϰ� ��ġ�� ���ڿ����� ������ ���ڿ����� ������ ���� ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �� �� �� �̵�, �̺� Ž��

��ó : USACO 2015O B4��
*/

char field[32][32], tpath[32], path1[103000][20], path2[103000][20], pal[262144][20];
int p1p = 0, p2p = 0;

void track1(int n, int x, int y, int pi) {
    tpath[pi] = field[x][y];
    if (x > 0) track1(n, x - 1, y, pi + 1);
    if (y > 0) track1(n, x, y - 1, pi + 1);
    if (x == 0 && y == 0) {
        strcpy(path1[p1p], tpath);
        p1p++;
    }
    tpath[pi] = '\0';
}

void track2(int n, int x, int y, int pi) {
    tpath[pi] = field[x][y];
    if (x < n - 1) track2(n, x + 1, y, pi + 1);
    if (y < n - 1) track2(n, x, y + 1, pi + 1);
    if (x == n - 1 && y == n - 1) {
        strcpy(path2[p2p], tpath);
        p2p++;
    }
    tpath[pi] = '\0';
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("palpath.in", "r");
        fo = fopen("palpath.out", "w");
    }
    int n, pp = 0, r = 0;
    void* v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", field[i]);
    }
    for (int i = 0; i < n; i++) {
        p1p = 0, p2p = 0;
        track1(n, i, n - i - 1, 0);
        track2(n, i, n - i - 1, 0);
        if (p1p > 100000 || p2p > 100000) return 1;
        qsort(path1, p1p, sizeof(char) * 20, strcmp);
        qsort(path2, p2p, sizeof(char) * 20, strcmp);
        for (int j = 0; j < p1p; j++) {
            if (j > 0 && !strcmp(path1[j], path1[j - 1])) continue;
            v = bsearch(path1[j], path2, p2p, sizeof(char) * 20, strcmp);
            if (v) {
                strcpy(pal[pp], path1[j]);
                pp++;
            }
        }
    }
    qsort(pal, pp, sizeof(char) * 20, strcmp);
    for (int i = 0; i < pp; i++) {
        if (i > 0 && !strcmp(pal[i], pal[i - 1])) continue;
        r++;
    }
    printf("%d", r);
    return 0;
}