#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : 1���� N(N <= 12, N�� ¦��)������ ���� ������� ���� ��� (N * 3 / 2)���� �ֿ� ���� �Ÿ� ���� ���� ����
������ �Ÿ� ���� ���Ѵ�.

�ذ� ��� : ��Ʈ��ŷ�� ���� ������ ����鼭 ��������� �Ÿ��� ������ �ʿ��� �ּ� �Ÿ��� ���Ѵ�. ������ �ʿ��� �ּ� �Ÿ���
��������� �Ÿ��� ���� �ִ� �̻��� �Ǵ� ������ Ž���� �����Ѵ�.
������ �ʿ��� �Ÿ��� ���� ���ʸ� ����� �������� ������ ���� ������ �Ѿ �� ���� ���Ͽ� ���� ������ ���Ѵ�.
(�ش� �������� ��� �̾����� ������), ���� ������ ����Ǹ� �ش� ���� ��������� �Ÿ��� �ѱ��.

�ֿ� �˰��� : ��Ʈ��ŷ, �޸���ƽ

��ó : USACO 2013O B4��
*/

int vis[16], ed[16][3], perm[16], order[16][16], dist[16][16];
const int fact[13] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600 };
int best = INF, stt;

int cmp1(const void* a, const void* b) {
    int ai = dist[stt][*(int*)a];
    int bi = dist[stt][*(int*)b];
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void track(int n, int x, int r, int c, int p) {
    //n : N, x : ���� �õ��ϴ� ��ȣ, r : ��������� �Ÿ�, c : ���ʸ� ����� ������ ��, p : ������ �ʿ��� �ּ� �Ÿ�
    if (x > n) {
        if (r < best) best = r;
        return;
    }
    if (r + p >= best) return; //���� ������ ���� ����ȭ

    int nxt, radd, cadd; //nxt : ������ ���� ��, radd : �ش� ���� �����Ͽ� �߰��Ǵ� �Ÿ�
    //cadd : �ش� ���� �����Ͽ� �߰��Ǵ� ���ʸ� ����� ������ ��(������ �� ���� ����)
    for (int i = 1; i <= n; i++) {
        nxt = order[perm[x - 1]][i];
        if (vis[nxt]) continue;
        vis[nxt] = x; //�ش� ��ġ�� ��ȣ�� �߰�
        perm[x] = nxt;
        radd = 0, cadd = 0;
        for (int j = 0; j < 3; j++) {
            radd += (vis[ed[nxt][j]] ? vis[nxt] - vis[ed[nxt][j]] : 0);
            cadd += (!vis[ed[nxt][j]]) * 2 - 1;
        }
        track(n, x + 1, r + radd, c + cadd, p + c + cadd - radd);
        vis[nxt] = 0;
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("haywire.in", "r");
        fo = fopen("haywire.out", "w");
    }
    srand((unsigned)time(NULL));

    int n, pn, th, tr;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
            order[i][j] = j;
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &ed[i][0], &ed[i][1], &ed[i][2]);
        for (int j = 0; j < 3; j++) {
            dist[i][ed[i][j]] = 1;
            dist[ed[i][j]][i] = 1;
        }
    }
    
    /*
    //������ȭ ����?
    for (int i = 0; i < 2000; i++) {
        //srand(rand() * 22 + 237 + i + rand() * (i + 39));
        pn = ((unsigned)rand() * 32768 + (unsigned)rand()) % fact[n];
        //if (i % 100 == 0) printf("%d\n", pn);
        for (int j = n; j > 0; j--) {
            pn %= fact[j];
            th = pn / fact[j - 1] + 1;
            for (int k = 1; k <= n; k++) {
                if (vis[k]) continue;
                if (--th == 0) {
                    vis[k] = 1;
                    perm[j] = k;
                    break;
                }
            }
        }

        tr = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 3; k++) {
                if (perm[ed[j][k]] > perm[j]) tr += perm[ed[j][k]] - perm[j];
            }
        }
        if (tr < best) best = tr;

        for (int j = 1; j <= n; j++) {
            vis[j] = 0;
            perm[j] = 0;
        }
    }

    //�Ÿ� ������ ���� �켱����?
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        stt = i;
        qsort(&order[i][1], n, sizeof(int), cmp1);
    }
    */

    track(n, 1, 0, 0, 0);
    printf("%d", best);
    return 0;
}