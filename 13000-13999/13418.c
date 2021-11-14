#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� �ǹ� ���� ����� �־��� ��, �� ����� ������/������ ���ΰ� �־�����.
����Ŭ�� ������ �ʵ��� �ǹ��� ���� ���� ������ ��, �������� �ִ밡 �� ���� �ּҰ� �� ���� ���� ������ ���̸� ���Ѵ�.

�ذ� ��� : �������� ��� 1, �������� ��� 0���� �ΰ� �ִ� ���д� Ʈ���� �ּ� ���д� Ʈ���� ���Ѵ�.
�ִ� ���д� Ʈ���� �������� �ּ� ���д� Ʈ���� ������ ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST

��ó : ���δ� 2016 F��
*/

int road[524288][3], g[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
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
    int n, m, a, b, c, rl = 0, rh = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= m; i++) {
        scanf("%d %d %d", &road[i][1], &road[i][2], &road[i][0]);
        road[i][0] = 1 - road[i][0];
        road[i][1]++;
        road[i][2]++;
    }
    qsort(road, m + 1, sizeof(int) * 3, cmp1);
    for (int i = 0; i <= m; i++) {
        if (find(road[i][1]) == find(road[i][2])) continue;
        uni(road[i][1], road[i][2]);
        rl += road[i][0];
    }
    for (int i = 0; i < 1024; i++) g[i] = 0;
    qsort(road, m + 1, sizeof(int) * 3, cmp2);
    for (int i = 0; i <= m; i++) {
        if (find(road[i][1]) == find(road[i][2])) continue;
        uni(road[i][1], road[i][2]);
        rh += road[i][0];
    }
    printf("%d", rh * rh - rl * rl);
    return 0;
}