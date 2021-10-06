#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100)���� �̸�(�빮��, 10�� ����)�� ������ �θ�-�ڽİ��谡 �־�����. �̶�, �� ���� �̸��� �־�����
���� �������� ���Ѵ�.(�������� ����, ...-great-grand-mother, ...-great-aunt, cousine, �����ڸ� ����(sister))

�ذ� ��� : ���� �� ���ڿ��� ������ ���� ��ȣ�� �����Ѵ�. �� ������ �ٽ� �� ���ڿ��� �̺� Ž���� �̿��� ���ڿ���
��ȣ�� �ٲ۴�. ��ȣ�� �ٲ� �������� ù ��°�� �������� �� ����, �ش� ���󿡼� DFS�� ���� ���������� ���� ���Ѵ�.
�� ��°�� �������� ������ �ʴ� ��쿡�� ģô�� �ƴϹǷ� �������谡 �ƴ� ���̴�.

�̸� ���ϰ� ���� ���� ���迡 ���� ��츦 ������ �����Ѵ�. ���� �׷��� ���� ��쿡�� �����ڸ� �������� Ȯ���ϰ�
�ƴϸ� cousine�� ����Ѵ�.
�׷��� ���� �ٸ��ٸ� �׷��� ���� �ʿ��� ���� �ʱ��� �ö�� ������ Ȯ���Ѵ�. �ݴ��ʰ� ���ٸ� �ڼ� �����̰�,
�׷� ���� ���� -great�̳� -grand�� �߰��ϰ� -mother�� ���̸� �ȴ�.
�ݴ��ʰ� ������ ������ �θ� ���ٸ� ��ī �����̰� ���� �׷����� ���� -great�� �߰��ϰ� -aunt�� ���δ�.
�� �� �ƴ϶�� ģô ����� cousine�� ���̸� �ȴ�.

�ֿ� �˰��� : ����, �׷��� �̷�, Ʈ��, LCA, ���̽� ��ũ, �̺� Ž�� ���

��ó : USACO 2018O B3��
*/

char bessie[16], elsie[16], rel[128][2][16], astr[256][16], rstr[256][16];
int ance[256], reln[128][2], ed[256][256], vis[256], level[256];
int rsp = 0;

void dfs(int x, int lv) {
    level[x] = lv;
    vis[x] = 1;
    for (int i = 1; i <= ed[x][0]; i++) {
        if (!vis[ed[x][i]]) dfs(ed[x][i], lv + 1);
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("family.in", "r");
        fo = fopen("family.out", "w");
    }
    int n, aa, bb, grand;
    void* v;
    scanf("%d %s %s", &n, bessie, elsie);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", rel[i][0], rel[i][1]);
        strcpy(astr[i * 2], rel[i][0]);
        strcpy(astr[i * 2 + 1], rel[i][1]);
    }
    strcpy(astr[n * 2], bessie);
    strcpy(astr[n * 2 + 1], elsie);
    qsort(astr, n * 2 + 2, sizeof(char) * 16, strcmp);
    for (int i = 0; i < n * 2 + 2; i++) {
        if (i > 0 && !strcmp(astr[i], astr[i - 1])) continue;
        strcpy(rstr[rsp++], astr[i]);
    }
    for (int i = 0; i < n; i++) {
        v = bsearch(rel[i][0], rstr, rsp, sizeof(char) * 16, strcmp);
        if (v == NULL) return 1;
        reln[i][0] = ((char(*)[16])v - rstr) + 1;
        v = bsearch(rel[i][1], rstr, rsp, sizeof(char) * 16, strcmp);
        if (v == NULL) return 1;
        reln[i][1] = ((char(*)[16])v - rstr) + 1;
    }
    v = bsearch(bessie, rstr, rsp, sizeof(char) * 16, strcmp);
    if (v == NULL) return 1;
    aa = ((char(*)[16])v - rstr) + 1;
    v = bsearch(elsie, rstr, rsp, sizeof(char) * 16, strcmp);
    if (v == NULL) return 1;
    bb = ((char(*)[16])v - rstr) + 1;

    for (int i = 0; i < n; i++) {
        ance[reln[i][1]] = reln[i][0];
        ed[reln[i][0]][++ed[reln[i][0]][0]] = reln[i][1];
        ed[reln[i][1]][++ed[reln[i][1]][0]] = reln[i][0];
    }

    grand = aa;
    while (ance[grand]) grand = ance[grand];
    dfs(grand, 1);
    if (!vis[aa] || !vis[bb]) {
        printf("%s", "NOT RELATED");
        return 0;
    }

    int ab;
    if (level[bb] > level[aa]) {
        ab = bb;
        while (level[ab] > level[aa]) ab = ance[ab];
        if (ab == aa) {
            printf("%s is the ", bessie);
            for (int i = 2; i < level[bb] - level[aa]; i++) printf("%s", "great-");
            if (level[bb] - level[aa] > 1) printf("%s", "grand-");
            printf("mother of %s", elsie);
        }
        else if (ance[ab] == ance[aa]) {
            printf("%s is the ", bessie);
            for (int i = 1; i < level[bb] - level[aa]; i++) printf("%s", "great-");
            printf("aunt of %s", elsie);
        }
        else printf("%s", "COUSINS");
    }
    else if (level[aa] > level[bb]) {
        ab = aa;
        while (level[ab] > level[bb]) ab = ance[ab];
        if (ab == bb) {
            printf("%s is the ", elsie);
            for (int i = 2; i < level[aa] - level[bb]; i++) printf("%s", "great-");
            if (level[aa] - level[bb] > 1) printf("%s", "grand-");
            printf("mother of %s", bessie);
        }
        else if (ance[ab] == ance[bb]) {
            printf("%s is the ", elsie);
            for (int i = 1; i < level[aa] - level[bb]; i++) printf("%s", "great-");
            printf("aunt of %s", bessie);
        }
        else printf("%s", "COUSINS");
    }
    else {
        if (ance[aa] == ance[bb]) printf("%s", "SIBLINGS");
        else printf("%s", "COUSINS");
    }

    return 0;
}