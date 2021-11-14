#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 10^9)���� M(M <= 300000, N)���� ������ ������ ������ �ַ��� �Ѵ�. �� ������� �� ���� ������ ������
������ �� �� �ִٸ�, ������ ���� ���� ���� ����� �ּ� �� ���� ���� �Ǵ��� ���Ѵ�.

�ذ� ��� : �� ������� �������ִ� ������ �ִ� ������ �������� �ΰ� �Ű� ���� Ž���� ������ ������ �ȴ�.

�ֿ� �˰��� : �Ķ��Ʈ��

��ó : COCI 12/13#1 4��
*/

int gem[327680];

long long getres(int m, int x) {
    long long r = 0;
    for (int i = 0; i < m; i++) {
        r += (gem[i] + x - 1) / x;
    }
    return r;
}

int main(void) {
    int n, m, lo = 1, hi = INF, mid;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &gem[i]);
    }
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (getres(m, mid) <= n) hi = mid;
        else lo = mid + 1;
    }
    printf("%d", lo);
    return 0;
}