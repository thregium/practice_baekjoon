#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10000)���� ������ P(P <= 100000)���� �������� �̷���� ����� ����ġ ���� �׷����� �־�����.
�̶�, �� �׷����� �� �������� N - 1���� �������� ����� �� �������� ��� �������� �̵� �� ���ƿ��� ����� �ּҷ� �Ϸ��� �Ѵ�.
�� ������ ������ �湮�� ��� ����� �־��� ��, �ش� �̵��� �ּ� ����� ���Ѵ�.

�ذ� ��� : ������ �̵� ��θ� �����غ���. �׷��� ���� ������ N - 1���̹Ƿ� ���д� Ʈ���� ���¸� �� ���̰�,
�� ������ �湮�� Ƚ���� ���� �Ǵ� ���� + 1(���� ������ ���)�� ���̴�. ����, �� ������ �̵��� Ƚ���� ��� 2ȸ���� �ȴ�.
���⼭ �� ������ �̿��� ������ ����ġ�� (���� ������ ����ġ * 2 + ���� ������ ����ġ)�� �θ� �ּ� ���д� Ʈ���� ����
�׷��� ���д� Ʈ���� ���� �� �ִ�. ���� ������ ���� ����ġ�� ���� �������� �θ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST

��ó : USACO 2008N G2��
*/

int road[103000][3], cost[10240], g[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, p, r = 0;
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }
    for (int i = 0; i < p; i++) {
        scanf("%d %d %d", &road[i][1], &road[i][2], &road[i][0]);
        road[i][0] <<= 1;
        road[i][0] += cost[road[i][1]] + cost[road[i][2]];
    }
    qsort(road, p, sizeof(int) * 3, cmp1);
    for (int i = 0; i < p; i++) {
        if (find(road[i][1]) != find(road[i][2])) {
            uni(road[i][1], road[i][2]);
            r += road[i][0];
        }
    }
    qsort(cost + 1, n, sizeof(int), cmp1);
    r += cost[1];
    printf("%d", r);
    return 0;
}