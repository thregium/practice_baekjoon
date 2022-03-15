#include <stdio.h>
#define INF 103000

/*
���� : N(N <= 100)���� ������ M(M <= 100)���� Ŀ�ǵ尡 �����Ѵ�. �� Ŀ�ǵ�� K(K <= 100)���� ������
�´� ��� �رݵȴ�. �� ������ ������ ������ �̻� �Ǵ� ������ ���� �־�����.
�� ������ �ö� ���� �ְ� ������ ���� ���ٸ� ��� ������ �ر��ϴ� ���� ������ �� ���Ѵ�.

�ذ� ��� : �� Ŀ�ǵ� ���� �ر� ������ �������� ���� ����, �� �׷����� ����Ŭ�� �ִ� �� ���θ�
Ȯ���ϴ� ������ ��ü �ر��� ������ �� ���θ� �Ǻ��� �� �ִ�. ����Ŭ�� ���� ��쿡�� ��ü �ر��� �����ϴ�.
�ر� ������ ����� ���� �� Ŀ�ǵ� ���� ���� ���� ��ġ�� �ʴ� ����, ���� �ʿ��� ū ���� ������
�ر��� �ؾ߸� �Ѵ�(������ �پ�� �� �����Ƿ�). �̸� �� �������� ���ָ� �׷����� �ϼ��ǰ�,
������ �����Ѵ�� ����Ŭ�� ã���� �ȴ�. N�� �����Ƿ� ����Ŭ ���δ� ���� ������� ã�� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����

��ó : JAG 2013SC A��
*/

char buff[8];
int comm[128][128][2], dist[128][128];

int small(int a, int b) {
    return a < b ? a : b;
}

int updown(int c1, int c2, int s) {
    int st1 = comm[c1][s][0], ed1 = comm[c1][s][1], st2 = comm[c2][s][0], ed2 = comm[c2][s][1];
    if (ed1 < st2) return -1;
    else if (ed2 < st1) return 1;
    else return 0;
}

int main(void) {
    int m, n, r = 1, k, s, t;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            comm[i][j][0] = -INF;
            comm[i][j][1] = INF;
        }
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d %s %d", &s, buff, &t);
            if (buff[0] == '>' && t > comm[i][s][0]) comm[i][s][0] = t;
            if (buff[0] == '<' && t < comm[i][s][1]) comm[i][s][1] = t;
        }
        for (int j = 1; j <= n; j++) {
            if (comm[i][j][0] > comm[i][j][1]) r = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) dist[i][j] = INF;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                t = updown(i, j, k);
                if (t < 0) dist[i][j] = 1;
                else if (t > 0) dist[j][i] = 1;
            }
        }
    }

    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (dist[i][i] != INF) r = 0;
    }
    printf("%s\n", r ? "Yes" : "No");
    return 0;
}