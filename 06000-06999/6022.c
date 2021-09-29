#include <stdio.h>
#include <stdlib.h>

/*
���� : R(R <= 50) * W(W <= 101, W�� Ȧ��) ũ���� �¼��� �ִ�. �̶�, ������ ���� ��� �¼��� ���� ��ȣ�ϰ�,
���ķδ� �� �¼����� �Ÿ��� ����� ������ ��ȣ�Ѵٸ� ��ȣ�ϴ� �¼��� ������ ��� �¼��� ���� ����Ѵ�.
�Ÿ��� ���� ��� ���� ���� ���� ��ȣ�ϰ�, ���� �ٿ����� ������ ���� ��ȣ�Ѵ�.

�ذ� ��� : �� �¼����� �Ÿ��� ��Ÿ����� ������ �̿��� ����ϰ� ����� ���´�.
�̸� �� �迭�� �ű� ����, �¼��� ��ġ�� �Բ� ����Ѵ�. �� ����, �� �迭�� �Ÿ� �� -> �� �� -> ���� ������ �����Ѵ�.
������ �迭���� �ٽ� �¼��� ��ġ�� ã�ƿͼ� ������ ����� ����, �� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ������, ����

��ó : USACO 2010J B2��
*/

int res[64][128], sorting[8192][2];

int sqr(int a) {
    return a * a;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai > bi ? 1 : -1;
    int ap = *((int*)a + 1);
    int bp = *((int*)b + 1);
    if ((ap >> 7) != (bp >> 7)) return (ap >> 7) < (bp >> 7) ? 1 : -1;
    else return ap > bp ? 1 : ap == bp ? 0 : -1;
}

int main(void) {
    int w, r;
    scanf("%d %d", &w, &r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < w; j++) {
            sorting[i * w + j][0] = sqr(i - (r - 1)) + sqr(j - (w >> 1));
            sorting[i * w + j][1] = i * 128 + j;
        }
    }
    qsort(sorting, r * w, sizeof(int) * 2, cmp1);
    for (int i = 0; i < r * w; i++) {
        res[sorting[i][1] >> 7][sorting[i][1] & 127] = i + 1;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}