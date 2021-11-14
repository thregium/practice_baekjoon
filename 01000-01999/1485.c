#include <stdio.h>
#include <stdlib.h>

/*
���� : 4���� ���� �־��� ��, 4���� ������ ���簢���� ���� �� �ִ��� ���Ѵ�. �� ���� ��ǥ�� ������ 100000 ������ �����̴�.

�ذ� ��� : ��� ���� �ֿ� ���� �Ÿ��� ���ϰ�, ������������ �����Ѵ�.
���� �� �簢���� ���簢���̶�� �� �밢���� ���̰� ���� ��� ���� ���̰� ���� ���̴�.
���� ���� �� �Ÿ� 2����, ������ �Ÿ� 4���� ���� �� �׷��� ���ҵ� ���� �Ÿ��� ���� ���ٸ� ���簢���̴�.

�ֿ� �˰��� : ������, ��Ÿ���, ����
*/

long long point[4][2], dist[8];

long long sqr(long long x) {
    return x * x;
}

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, p;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 4; i++) {
            scanf("%lld %lld", &point[i][0], &point[i][1]);
        }
        p = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                dist[p++] = sqr(point[i][0] - point[j][0]) + sqr(point[i][1] - point[j][1]);
            }
        }
        qsort(dist, p, sizeof(long long), cmp1);
        if (dist[0] == dist[1] && dist[2] == dist[5]) printf("1\n");
        else printf("0\n");
    }
    return 0;
}