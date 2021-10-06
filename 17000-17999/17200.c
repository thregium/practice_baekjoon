#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 25)������ �ҵ��� �ְ�, �� �ҵ��� 25�� ������ ������ ���� �ִ�. �� �ҵ��� �ƹ� ������ ���� �ҿ���
��ȭ�Ͽ� ������ �߰��Ǿ��ٰ� �� ��, ������ �� ������ ��ȭ�Ͽ� �� �ҵ��� ������ ��� ������ �� �ִ��� ���Ѵ�.
��, ������ �Ϻ��� ���� ���� ���� ����.

�ذ� ��� : ���� � ���� ������ �ٸ� ���� ��� ������ �����Ѵٸ� �� �Ҵ� �ٸ� ���� �ڼ��� ���̴�.
�̸� �̿��� �� ������ ���� �ڼ��� ������ ���� �ҵ��� ���� �ܹ��� �������� �����Ų��.
�̶�, �ڽ� �� �ƴ϶� ����, ������... � ������ �ǰ� �ȴ�. �̴� �� �ڼտ� ���� �ڼ��� �ڼյ��� Ȯ���ϸ�
�ڼ��� �ڼ��� �ҵ�� ���ϴ� ������ �����ִ� ������� �ڽĵ鸸 ���� �� �ִ�.

�ڽĵ鸸 ���� �� �ְ� �Ǹ� ����������, �� �ҵ�(+ �ƹ� ������ ���� ������ ���� ��)����
����Ͽ� ��� �ҵ��� 2ȸ �̻� ��ġ�� �ʰ� �ڽ� ����� ���� �������� Ȯ���Ѵ�.
�׷��� ��찡 �����ϸ� �׷��� �Ұ� ������ ���� ������ ������ ���̴�.
�������� �ʴ´ٸ� ������ �� ���� ����̴�.

�ֿ� �˰��� : �׷��� �̷�, Ʈ��, ���� ����?

��ó : USACO 2019O B3��
*/

char evo[32][32][32];
int ed[32][32], cnt[32], vis[32];
int dup = 0;

int dfs(int x) {
    //dfs�� ���� ����Ʈ���� ũ�⸦ ����
    int r = 1;
    vis[x] = 1;
    for (int i = 1; i <= ed[x][0]; i++) {
        if (vis[ed[x][i]]) dup++;
        else r += dfs(ed[x][i]);
    }
    return r;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("evolution.in", "r");
        fo = fopen("evolution.out", "w");
    }
    int n, tmp, adde;
    scanf("%d", &n);
    tmp = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cnt[i]);
        tmp += cnt[i];
        for (int j = 0; j < cnt[i]; j++) {
            scanf("%s", evo[i][j]);
        }
    }
    n += !tmp; //������ ���� �Ұ� ���ٸ� �׷��� ������ �Ҹ� �߰���
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            adde = 1;
            for (int k = 0; k < cnt[i]; k++) {
                tmp = 0;
                for (int l = 0; l < cnt[j]; l++) {
                    if (strcmp(evo[i][k], evo[j][l]) == 0) {
                        tmp = 1;
                        break;
                    }
                }
                if (tmp == 0) {
                    adde = 0;
                    break;
                }
            }
            if (adde) ed[i][++ed[i][0]] = j; //���� ��� ������ ���ԵǴ� �Ұ� �ִٸ� �� ���� �ڼ� ���� ��
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= ed[j][0]; k++) {
                if (k < 1) continue;
                tmp = 0;
                for (int l = 1; l <= n; l++) vis[l] = 0;
                dfs(ed[j][k]);
                vis[ed[j][k]] = 0;
                for (int l = 1; l <= ed[j][0]; l++) {
                    if (!vis[ed[j][l]]) continue;
                    for (int m = l; m < ed[j][0]; m++) {
                        ed[j][m] = ed[j][m + 1];
                    }
                    ed[j][ed[j][0]] = 0;
                    ed[j][0]--; //�ڼ��� �ڼ��� �ҵ�� ���ϴ� ������ ������
                    k--;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) vis[j] = 0;
        dup = 0; //Ʈ�� ���°� �ƴϸ� �ȵ�
        if (dfs(i) == n) {
            //i�� ��尡 ��Ʈ
            if (dup == 0) {
                printf("%s", "yes");
                return 0;
            }
        }
    }
    printf("%s", "no");
    return 0;
}