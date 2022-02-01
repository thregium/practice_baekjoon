#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 200000)���� ���� �뼱�� �������� �ִ�. �� ���̶� ��ġ�� �뼱�� ���� ������ ��
���� ���� ������� �����Ѵٰ� �� ��, ���� ������ ���� �뼱���� ��ǥ ������������ ����Ѵ�.

�ذ� ��� : �� ���� �뼱�� �������� ������ �迭�� ���� �� ���� �뼱�� ���� 1 �̻��� ���� ������
�ϳ��� ���� �뼱���� �Ѵ�. ����� �� �� ���� ���� ������ �����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : ������ 2021 D��
*/

int pos[409600][2], res[204800][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai > bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s, e, c = 0, cnt = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &s, &e, &c);
        pos[i << 1][0] = s;
        pos[i << 1][1] = c;
        pos[(i << 1) + 1][0] = e;
        pos[(i << 1) + 1][1] = -c;
    }
    qsort(pos, n * 2, sizeof(int) * 2, cmp1);
    for (int i = 0; i < (n << 1); i++) {
        if (pos[i][1] > 0) {
            if (cnt++ == 0) {
                res[r][0] = pos[i][0];
                c = INF;
            }
            if (pos[i][1] < c) c = pos[i][1];
        }
        else {
            if (--cnt == 0) {
                res[r][1] = pos[i][0];
                res[r++][2] = c;
            }
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
    }
    return 0;
}