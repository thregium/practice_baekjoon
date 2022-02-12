#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 100)���� ������ M(M <= 1000)���� �������� �̷���� �ܹ��� ����ġ(<= 1000, �ڿ���) �׷�������
���� A���� B�� C�� �̵��ϵ��� ������ ���� ���� �ּ� ����ġ�� ���Ѵ�.

�ذ� ��� : �÷��̵�-���� �˰����� ���� ��� ���� ���� �Ÿ��� ���� ����, ��� �߰� ������ ����
�ش� ������ �б������� �ϵ��� ������ ������ ���� ����ġ �� ��� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����, ���Ʈ ����

��ó : JDC 2006 F��
*/

int dist[128][128], ed[128][128];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, a, b, c, x, y, z;
    long long r;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2006D\\judge-data\\F1", "r", stdin);
    while (1) {
        scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = INF;
                ed[i][j] = 0;
            }
            dist[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &z);
            ed[x][y] = z;
            //ed[y][x] = z;
            dist[x][y] = z;
            //dist[y][x] = z;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        /*
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (dist[a][i] > dist[a][j]) ed[i][j] = 0;
                else ed[j][i] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = INF;
                if (ed[i][j]) dist[i][j] = ed[i][j];
            }
            dist[i][i] = 0;
        }
        */
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        r = INF;
        for (int i = 1; i <= n; i++) {
            r = small(r, (long long)dist[a][i] + dist[i][b] + dist[i][c]);
        }
        printf("%lld\n", r);
    }
    return 0;
}