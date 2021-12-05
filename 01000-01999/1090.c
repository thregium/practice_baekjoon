#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 50)���� üĿ�� �ſ� ū üĿ �ǿ� �ִ�. �� üĿ ������ ��ĥ �� �ְ�, �����¿�� 1ĭ�� ������ �� �ִ�.
�� ������ ��ġ(�ڿ���, <= 10^6)�� �־��� ��, üĿ ������ 1��, 2��, ..., N�� ��ġ�� ���� �ʿ��� �ּ� �̵� Ƚ���� ���Ѵ�.

�ذ� ��� : �� üĿ ������ ������ ��ġ�� �� ������ ��ǥ�� �߾Ӱ��̴�.
����, �� üĿ ���� �ִ� X��ǥ�� Y��ǥ�� ��ġ�� Ȯ���ϸ� �ȴ�. �� ��ġ������ �Ÿ��� ���� ����, ����� ������ �����Ѵ�.
K���� �Ÿ��� ���� �Ź� ���ϰ�, �� �� ���� ����� �͵��� ã�Ƴ�����. �������� �� ������ �Ÿ� ���� ���� ���� �͵��� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, �׸��� �˰���?

��ó : SRM 423 D1A / D2B
*/

int pos[64][2], dist[64], res[64];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, y, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < n; i++) res[i] = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x = pos[i][0], y = pos[j][1];
            for (int k = 0; k < n; k++) {
                dist[k] = abs(pos[k][0] - x) + abs(pos[k][1] - y);
            }
            qsort(dist, n, sizeof(int), cmp1);
            s = 0;
            for (int k = 0; k < n; k++) {
                s += dist[k];
                if (s < res[k]) res[k] = s;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}