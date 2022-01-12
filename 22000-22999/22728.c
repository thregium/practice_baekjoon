#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� �����ٰ� M(M <= 1000)���� �����ٷ� �̷���� ��ٸ�Ÿ�⿡�� A�� ���� ���� �̾����� �� ���Ѵ�.
��, ���� ���̿��� �ϳ��� �����ٿ� ���� ���� ���� ����Ǵ� ���� ����.

�ذ� ��� : �� �������� ���̼�(������ �Ʒ���)���� ������ ����, A�� �ٿ� ����Ǵ� ���μ��� ������,
�ش� ���μ����� �ű�� �ൿ�� �ݺ��Ѵ�. ��� �Ϸ�� ���� �Űܰ� ������ ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : JAG 2006D B��
*/

int hor[1024][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, a;
    while (1) {
        scanf("%d %d %d", &n, &m, &a);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &hor[i][0], &hor[i][1], &hor[i][2]);
        }
        qsort(hor, m, sizeof(int) * 3, cmp1);
        for (int i = 0; i < m; i++) {
            if (hor[i][1] == a) a = hor[i][2];
            else if (hor[i][2] == a) a = hor[i][1];
        }
        printf("%d\n", a);
    }
    return 0;
}