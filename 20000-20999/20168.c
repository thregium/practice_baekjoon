#include <stdio.h>

/*
���� : N(N <= 10)���� �������� �̷���� ����� ����ġ �׷������� C(C <= 10000)�� ������� ���� A���� ���� B�� �̵��ϴ�
��� ��� �߰��� ������ ������ ����ġ �ִ��� ���� ���� ���� ����ġ �ִ��� ���Ѵ�.
�� ������ ����ġ�� 1000 ������ �ڿ����̴�.

�ذ� ��� : ��Ʈ��ŷ�� ���� ��� ��츦 ���캻��. �߰��� ����� �Ѵ� ���� Ȯ������ �ʴ´�.

�ֿ� �˰��� : �׷��� �̷�, ��Ʈ��ŷ

��ó : ��ȣ���� 1ȸ 6��
*/

typedef struct road {
    int ed;
    int fee;
} road;

int rdc[16], vis[16];
road rd[16][16];
int best = 103000;

void track(int a, int b, int c, int m) {
    if (a == b) {
        if (m < best) best = m;
        return;
    }
    for (int i = 0; i < rdc[a]; i++) {
        if (!vis[rd[a][i].ed] && rd[a][i].fee <= c) {
            vis[rd[a][i].ed] = 1;
            track(rd[a][i].ed, b, c - rd[a][i].fee, rd[a][i].fee > m ? rd[a][i].fee : m);
            vis[rd[a][i].ed] = 0;
        }
    }
}

int main(void) {
    int n, m, a, b, c, u, v, f;
    scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &f);
        rd[u][rdc[u]].ed = v;
        rd[u][rdc[u]++].fee = f;
        rd[v][rdc[v]].ed = u;
        rd[v][rdc[v]++].fee = f;
    }
    vis[a] = 1;
    track(a, b, c, 0);
    printf("%d", best == 103000 ? -1 : best);
    return 0;
}