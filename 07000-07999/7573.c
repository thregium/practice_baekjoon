#include <stdio.h>

/*
���� : N * N(N <= 10000) ������ ��ǥ �ȿ� M(M <= 100)������ ����Ⱑ �ִ�. �̶�, �ѷ��� L(L <= 100) ������
�׹��� ĥ �� �ִٸ� ����⸦ �ִ� �� ���� ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : �� ����Ⱑ �ִ� ��ǥ�� X��ǥ�� Y��ǥ�� ���� �ش� ��ǥ���� �����ϴ� ������ ��� �׹��� �ĺ��鼭
����Ⱑ ���� ���� �� �� �ִ� ��츦 ã���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : ���� 2013�� ��2��
*/

int fish[128][2];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, l, m, r = 0, c, tx, ty;
    scanf("%d %d %d", &n, &l, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &fish[i][0], &fish[i][1]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            for (int k = 1; k < (l >> 1); k++) {
                c = 0;
                tx = small(fish[i][0], fish[j][0]);
                ty = small(fish[i][1], fish[j][1]);
                for (int p = 0; p < m; p++) {
                    if (fish[p][0] >= tx && fish[p][1] >= ty && fish[p][0] <= tx + k && fish[p][1] <= ty + (l >> 1) - k) c++;
                }
                if (c > r) r = c;
            }
        }
    }
    printf("%d", r);
    return 0;
}