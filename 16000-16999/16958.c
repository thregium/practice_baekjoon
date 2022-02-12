#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 1000)���� ������ ��ġ(|| <= 2000)�� Ư���� ���� ���ΰ� �־�����.
�� ���� ���� �̵��� ����ư �Ÿ���ŭ�� �ð��� �ҿ��Ѵ�. Ư���� ���ó����� ���� �̵��� �����ϰ�,
���� �̵��� T(T <= 2000)��ŭ�� �ð��� �ҿ�ȴ�. �̶�, �� ���� A, B�� ���� �ִ� �̵� �ð���
M(M <= 1000)�� ���Ѵ�.

�ذ� ��� : ���� ������ ��ġ�鿡�� ��� ���� �ֿ� ���� �ҿ� �ð��� ���Ѵ�.
�׸��� �÷��̵�-���� �˰����� ���� ��� ���� �ֿ� ���� �̵� �ð��� ���ϰ� �̸� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����

��ó : ?
*/

int dist[1024][1024], city[1024][3];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, t, m, a, b;
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[i][j] = INF;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &city[i][0], &city[i][1], &city[i][2]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = abs(city[i][1] - city[j][1]) + abs(city[i][2] - city[j][2]);
            if (city[i][0] & city[j][0]) dist[i][j] = small(dist[i][j], t);
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", dist[a][b]);
    }
    return 0;
}