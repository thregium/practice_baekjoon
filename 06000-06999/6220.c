#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 10)������ ������ ����ؼ� C(C <= 1000)���� ������� �Ѵ�. ������ ���� ���� ����Ͽ� ������� ��
����� ������ ������ ���Ѵ�. ��, �׻� C���� ���� �� �ִ� ��츸 �־�����.

�ذ� ��� : ������ ����� C���� ����� ��츦 ��Ʈ��ŷ�� �̿��Ͽ� �ذ��Ѵ�. �̶�, ������ C���� ������� ����
����� ���� ���� �ּҷ����� ���� ������ ����ߴٸ� �߰��� Ž���� ������ ���� ������ Ž���ϵ��� �Ѵ�.
����, ������ ������ ��� C���� ���� �� ���ų� �ּҷ����� ���� ����Ѵٸ� �ٷ� �����Ͽ� �ӵ��� �� ���� �� �ִ�.

�ֿ� �˰��� : ��Ʈ��ŷ

��ó : USACO 2007J B2��
*/

int coins[16];
int res = INF;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

void track(int n, int x, int m, int y, int z) {
    if (x == n) {
        if (m == y && z < res) res = z;
        return;
    }
    if (x == n - 1) {
        if ((m - y) % coins[x] || (m - y) / coins[x] >= res) return;
        else track(n, x + 1, m, m, z + (m - y) / coins[x]);
    }
    for (int i = 0; y + i * coins[x] <= m && z + i < res; i++) {
        track(n, x + 1, m, y + i * coins[x], z + i);
    }
}

int main(void) {
    int c, n;
    scanf("%d %d", &c, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    qsort(coins, n, sizeof(int), cmp1);
    track(n, 0, c, 0, 0);
    printf("%d", res);
    return 0;
}