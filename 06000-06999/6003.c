#include <stdio.h>
#define INF 42933964230

/*
���� : N(N <= 2000)���� ������ �ְ�, ������ ��ǥ�� 100000 ������ �ڿ����̴�. �̶�, ���� ����� �� ���� ���� ���Ѵ�.
���� ����� ���� �����ϴ�.

�ذ� ��� : ��Ÿ����� ������ �̿��� ��� ���� �Ÿ��� ���캻 ����, ���� ����� ���� ã���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : USACO 2009N B1��
*/

int coord[2048][2];

long long sqr(long long x) {
    return x * x;
}

long long getdist(int a, int b) {
    return sqr(coord[a][0] - coord[b][0]) + sqr(coord[a][1] - coord[b][1]);
}

int main(void) {
    int n, b1 = -1, b2 = -1;
    long long best = INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &coord[i][0], &coord[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (getdist(i, j) < best) {
                best = getdist(i, j);
                b1 = i;
                b2 = j;
            }
        }
    }
    if (b1 < 0) return 1;
    printf("%d %d", b1, b2);
    return 0;
}