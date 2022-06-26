#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 103000

/*
���� : N(N <= 150)���� L(L <= 40)�� ��Ʈ�� �̷���� ���ڿ����� �ִ�.
��� ���ڿ��� ��Ʈ���� ������ ������ �ݺ��Ͽ� ���ϴ� ��Ʈ��� �̷���� ���ڿ��� ���հ�
������ ���ڿ����� ������ ���� �� �ִ� �� ���Ѵ�. �־��� ���ڿ���� ���ϴ� ���ڿ����� ��� ���� �ٸ���.

�ذ� ��� : ��ǥ ��Ʈ ���ڿ��� ������ ����, �տ������� �ϳ��� ������ �Ͱ� ������ ���� ����
�ٿ����� �ش� ���ڿ����� ������ ����� ���� �� Ȯ���Ѵ�.
���� �ʴٸ� �ٷ� Ž���� �����Ѵ�. �� Ž������ ������ �� �� �� ������ Ƚ���� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ��Ʈ����ŷ, ��Ʈ��ŷ, ����

��ó : GCJ 2014A A2��
*/

char ini[256][64], req[256][64], res[256][64], sti[256][64];
int resc;

void track(int n, int l, int p, int r) {
    if (l == p) {
        if (r < resc) resc = r;
        return;
    }
    else if (r >= resc) return;
    int ok = 1;
    for (int i = 0; i < n; i++) {
        res[i][p] = ini[i][p];
        res[i][p + 1] = '\0';
        strcpy(sti[i], res[i]);
    }
    qsort(sti, n, sizeof(char) * 64, strcmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= p; j++) {
            if (sti[i][j] != req[i][j]) {
                ok = 0;
                break;
            }
        }
        if (ok == 0) break;
    }
    if (ok) track(n, l, p + 1, r);

    ok = 1;
    for (int i = 0; i < n; i++) {
        res[i][p] = '1' - ini[i][p] + '0';
        res[i][p + 1] = '\0';
        strcpy(sti[i], res[i]);
    }
    qsort(sti, n, sizeof(char) * 64, strcmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= p; j++) {
            if (sti[i][j] != req[i][j]) {
                ok = 0;
                break;
            }
        }
        if (ok == 0) break;
    }
    if (ok) track(n, l, p + 1, r + 1);
}

int main(void) {
    int t, n, l;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &l);
        for (int i = 0; i < n; i++) {
            scanf("%s", ini[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", req[i]);
        }
        qsort(req, n, sizeof(char) * 64, strcmp);

        resc = INF;
        track(n, l, 0, 0);
        if (resc == INF) printf("Case #%d: NOT POSSIBLE\n", tt);
        else printf("Case #%d: %d\n", tt, resc);
    }
    return 0;
}