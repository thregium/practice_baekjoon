#include <stdio.h>
#define INF 1012345678

/*
���� : ���� D(D <= 10000)�� ���� ������ �Ѵ�. N(N <= 12)���� �������� ���� ��,
D������ �ִ� �Ÿ��� ���Ѵ�.

�ذ� ��� : ���� �� ���������� �ִ� �Ÿ��� ���̳��� ���α׷����� ���� ���Ѵ�.
�������� ������ ��� �������� ������ ��ο͵� ���غ���, �� �ܿ��� �� ĭ + 1�� �θ� �ȴ�.

�ֿ� �˰��� : DP
*/

int dist[10240], sc[16][3];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, d;
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &sc[i][0], &sc[i][1], &sc[i][2]);
    }
    for (int i = 1; i <= d; i++) dist[i] = INF;
    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < n; j++) {
            if (sc[j][1] == i) dist[i] = small(dist[i], dist[sc[j][0]] + sc[j][2]);
        }
        dist[i] = small(dist[i], dist[i - 1] + 1);
    }
    printf("%d", dist[d]);
    return 0;
}