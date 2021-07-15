#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 1000)���� ������ ��ǥ�� �־�����. �̶�, ���鳢�� ���� �����Ͽ� ������ ���� �׷��� ���·� ������� �� ��,
���� �� ������ ���̸� ���� ª�� �� �� ���� �� ���� ����^2�� ���Ѵ�.

�ذ� ��� : ũ�罺Į �˰����� ���� �� �� ������ MST�� ���� �� ���� �� ������ ���̸� ã���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST

��ó : USACO 2016D G1��
*/

int pos[1024][2], dist[1048576][2], g[1024];
int dd = 0, uc = 1;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getdist(int a, int b) {
    return (pos[a][0] - pos[b][0]) * (pos[a][0] - pos[b][0]) + (pos[a][1] - pos[b][1]) * (pos[a][1] - pos[b][1]);
}

int find(int x) {
    if (!g[x]) return x;
    return g[x] = find(g[x]);
}

void uni(int a, int b) {
    if (find(a) == find(b)) return;
    g[find(a)] = find(b);
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("moocast.in", "r");
        fo = fopen("moocast.out", "w");
    }
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            dist[dd][0] = getdist(i, j);
            dist[dd++][1] = i * 32768 + j;
        }
    }
    qsort(dist, dd, sizeof(int) * 2, cmp1);
    for (int i = 0; i < dd; i++) {
        a = (dist[i][1] >> 15);
        b = (dist[i][1] & 32767);
        if (find(a) == find(b)) continue;
        uni(a, b);
        uc++;
        if (uc == n) {
            printf("%d", dist[i][0]);
            return 0;
        }
    }
    return 0;
}