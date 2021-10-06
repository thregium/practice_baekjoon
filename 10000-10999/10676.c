#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : 10000���� ���ÿ� N(N <= 500)���� ��ӵ��ΰ� �ְ�, �� ��ӵ��δ� 500�� ������ ���ø� �����Ѵ�.
�� ��ӵ����� �Ϻθ� ź ��쿡�� ���(<= 1000)�� ���� �ȴٸ� ��ӵ��θ� 2�� ���Ϸ� Ÿ��
���� A���� ���� B�� �̵��ϴµ� �ʿ��� �ּ� �ݾ��� ���Ѵ�. �̵��� �Ұ����ϴٸ� -1�� ����Ѵ�.

�ذ� ��� : A���� �̵��� ������ �� ���ÿ� ���� �ʿ��� ��ӵ��� ��ݰ� �� ���ÿ��� B�� �̵��� ������ ���ÿ�
���� �ʿ��� ��ӵ����� ����� �����Ѵ�. �� ����, �� ���� ���� ���� ���� ���� ���� ���� ���ϰ�,
A���� B�� �ٷ� �̵��� �����ϴٸ� �� ���� ���� ���� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �� �� �� �̵�

��ó : USACO 2015J B2��
*/

int cost[512], rc[512], route[512][512], dist[10240], dist2[10240];
char chk[10240];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cowroute.in", "r");
        fo = fopen("cowroute.out", "w");
    }
    int a, b, n, c, r = INF;
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cost[i], &rc[i]);
        for (int j = 0; j < rc[i]; j++) {
            scanf("%d", &route[i][j]);
        }
    }
    for (int i = 0; i < 10240; i++) {
        dist[i] = INF;
        dist2[i] = INF;
    }
    for (int i = 0; i < n; i++) {
        c = 0;
        for (int j = 0; j < 10240; j++) chk[j] = 0;
        for (int j = 0; j < rc[i]; j++) {
            chk[route[i][j]] = 1;
            if (route[i][j] == a) c = 1;
            if (c) dist[route[i][j]] = small(dist[route[i][j]], cost[i]);
            if (route[i][j] == b) {
                for (int k = 0; k < 10240; k++) {
                    if (chk[k]) dist2[k] = small(dist2[k], cost[i]);
                }
            }
        }
    }

    r = small(r, dist[b]);
    for (int i = 0; i < 10240; i++) r = small(r, dist[i] + dist2[i]);
    printf("%d", r == INF ? -1 : r);
    return 0;
}