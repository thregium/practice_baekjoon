#include <stdio.h>
#include <stdlib.h>

/*
���� : N * N(N <= 50) ũ���� ���ڿ��� M(M <= N^2)���� ���̾�� ���� ������ �־��� ��, K(K <= 1000)�� ����
��� ���̾�� ���� ���� ���Ѵ�. (��Ģ ����)

�ذ� ��� : ������ �־��� ���Ǵ�� �ùķ��̼��Ѵ�. �䷯�� ������ ������ ������ ���� ������ ������ �� �ְ�,
���� ĭ�� �ִ��� ���δ� ������ �ϸ� �� �� �ִ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ����
*/

int fb[10240][5], nfb[10240][5], sums[5];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int aj = *((int*)a + 1);
    int bi = *(int*)b;
    int bj = *((int*)b + 1);
    if (ai != bi) return ai > bi ? 1 : -1;
    return aj > bj ? 1 : aj == bj ? 0 : -1;
}

int main(void) {
    int n, m, k, mn;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &fb[i][j]);
        }
    }
    for (int i = 0; i < k; i++) {
        mn = 0;
        for (int j = 0; j < m; j++) {
            nfb[j][0] = ((fb[j][0] - 1 + dxy[fb[j][4]][0] * fb[j][3]) % n + n) % n + 1;
            nfb[j][1] = ((fb[j][1] - 1 + dxy[fb[j][4]][1] * fb[j][3]) % n + n) % n + 1;
            nfb[j][2] = fb[j][2], nfb[j][3] = fb[j][3], nfb[j][4] = fb[j][4];
        }
        nfb[m][0] = -1;
        qsort(nfb, m, sizeof(int) * 5, cmp1);
        for (int j = 0; j < m; j++) {
            sums[0]++;
            sums[2] += nfb[j][2];
            sums[3] += nfb[j][3];
            if (nfb[j][0] == nfb[j + 1][0] && nfb[j][1] == nfb[j + 1][1]) {
                if ((nfb[j][4] ^ nfb[j + 1][4]) & 1) sums[4] = 1;
                continue;
            }
            if (sums[0] == 1) {
                for (int k = 0; k < 5; k++) {
                    fb[mn][k] = nfb[j][k];
                }
                mn++;
            }
            else if (sums[2] >= 5) {
                for (int k = 0; k < 4; k++) {
                    fb[mn][0] = nfb[j][0];
                    fb[mn][1] = nfb[j][1];
                    fb[mn][2] = sums[2] / 5;
                    fb[mn][3] = sums[3] / sums[0];
                    fb[mn][4] = k * 2 + sums[4];
                    mn++;
                }
            }
            for (int k = 0; k < 5; k++) sums[k] = 0;
        }
        m = mn;
    }
    
    for (int i = 0; i < m; i++) {
        sums[2] += fb[i][2];
    }
    printf("%d", sums[2]);
    return 0;
}