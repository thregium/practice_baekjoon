#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 100)���� ������ R(R <= 100)���� ����� �������� �̷���� �׷����� �־�����.
�� �׷������� �� ���������� ����(<= 30)�� ������ ����ġ(<= 15)�� �־����� ����ġ M(M <= 15) ���� �ȿ� �ִ�
������ ���� ���� ���� ū ������ ���� ���� ���Ѵ�.

�ذ� ��� : �÷��̵�-�ͼ� �˰����� �̿��� �� ���� ���� �Ÿ��� ���Ѵ�. �� ����, ��� ��������
�ش� �������� ����ؼ� ����ġ M ���� �ִ� ������ ���� ���� ���ϰ� �� �� ��� ���� ū ���� ���� �ȴ�.
�̶�, �ڱ� �ڽ����� �̵��ϴ� ��쿡�� �Ÿ��� ������� ���ؾ� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-�ͼ�

��ó : ������ 2017M D��
*/

int dist[128][128], item[128];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, r, a, b, l;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &item[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < r; i++) {
        scanf("%d %d %d", &a, &b, &l);
        dist[a][b] = small(dist[a][b], l);
        dist[b][a] = small(dist[b][a], l);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    r = 0;
    for (int i = 1; i <= n; i++) {
        a = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m || i == j) a += item[j];
        }
        if (a > r) r = a;
    }
    printf("%d", r);
    return 0;
}
