#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 32000)���� ���� ���򼱻� �����ִ�. ���� �������� ���̰� �־��� ��,
��� ���� ���� ���� �ʿ��� ������ Ƚ���� ���Ѵ�. ��, ���� �� ���� �ڸ��� �Ϳ� ���Ե��� �ʴ´�.

�ذ� ��� : ���� ������ ������ ������ ����, ���� �ڸ��� ���� �� ��� ������ ��ġ�� ���� ���� ����
������ �ڸ��� ���� �ݺ��ϴ� ���� ������ ����̴�. �� ���� �ݵ�� �߶�� ������ ���� �ڸ��� �߸��� �ʴ� ���� ����� ������
�����̱� �����̴�.

���� �ڸ� ������ �����ϴ� ��ġ�� �� ���� �ٸ� �ٵ��� ������ ã�� ���� �� ������ �˰����� �̿��� �� �ִ�.
���� �����ϴ� ������� ������ �迭�� �ϳ� �� ���� ����, ������ ������ ������ �迭�� ������Ű�� ����̴�.

�ֿ� �˰��� : �׸��� �˰���, ����, �� ������

��ó : USACO 2006O B5��
*/

int leash[32768][2], fronts[32768][2], backs[32768][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0, fp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &leash[i][0], &leash[i][1]);
        leash[i][1] += leash[i][0];
    }
    qsort(leash, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        fronts[i][0] = leash[i][0];
        fronts[i][1] = leash[i][1];
        backs[i][0] = leash[i][1];
        backs[i][1] = i;
    }
    qsort(fronts, n, sizeof(int) * 2, cmp2);
    for (int i = 0; i < n; i++) {
        fronts[i][1] = i;
    }
    qsort(fronts, n, sizeof(int) * 2, cmp1);
    qsort(backs, n, sizeof(int) * 2, cmp1);

    for (int i = 0; i < n; i++) {
        if (backs[i][1] < 0) continue;
        r++;
        backs[i][1] = -1;
        while (fronts[fp][0] < backs[i][0] && fp < n) {
            backs[fronts[fp][1]][1] = -1;
            fp++;
        }
    }
    printf("%d", r);
    return 0;
}