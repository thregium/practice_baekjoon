#include <stdio.h>
#include <stdlib.h>

/*
���� : P(P <= 1000)���� ������ W(W <= 50000)���� �������� �̷���� �׷������� �� �� c�� w ���̸� �մ� ������ ���Ѵ�.

�ذ� ��� : ũ�罺Į �˰����� �����Ͽ� Ǯ �� �ִ�. �������� ������ ū ������ ������ ����, c�� w�� ����� �� ����
���Ͽ�-���ε带 �̿��� �� �������� �̾����. c�� w�� ����Ǵ� ������ ������ ���� �ȴ�.
������� �ʴ´ٸ� 0�� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���Ͽ� ���ε�, MST

��ó : ACMSPCD 2015 F��
*/

int road[51200][3], g[1024];

int cmp1(const void* a, const void* b) {
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
    int p, w, c, v;
    scanf("%d %d", &p, &w);
    scanf("%d %d", &c, &v);
    c++, v++;
    for (int i = 0; i < w; i++) {
        scanf("%d %d %d", &road[i][1], &road[i][2], &road[i][0]);
        road[i][1]++, road[i][2]++;
    }
    qsort(road, w, sizeof(int) * 3, cmp1);
    for (int i = 0; i < w; i++) {
        uni(road[i][1], road[i][2]);
        if (find(c) == find(v)) {
            printf("%d", road[i][0]);
            return 0;
        }
    }
    printf("0");
    return 0;
}