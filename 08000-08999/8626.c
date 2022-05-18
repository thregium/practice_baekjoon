#include <stdio.h>
#include <stdlib.h>

/*
���� : N_i(N_i <= 1000)���� ��ǰ�� 3���� ������ ���� �ִ�. �� ������ ���(<= 10^9)��,
�� ��ǰ�� ����(<= 10^9)�� �־����� ��ü ��ǰ�� ��� * ���� ���� �ִ��� ���ݺ��� ū ����
�������� ���Ѵ�.

�ذ� ��� : �� �� ��ǰ�� ��� * ���� �� ���� ���� ����ص� ����, �����ϰ� ������ ��ǰ�鿡 ����
�� �� ��ǰ�� �����Ͽ� �ִ��� ���� �̻��� �Ǵ� ���� ������ �� �����͸� �̿��� �� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �� ������, �� �� �� �̵�

��ó : JPOI 2008 2-2��
*/

long long n[3], factory[3][1024], bk[1048576];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int b, k, z, bkcnt = 0, r = 0, pt = 0;
    long long best;
    scanf("%d %d %d", &b, &k, &z);
    for (int i = 0; i < 3; i++) {
        scanf("%lld", &n[i]);
        for (int j = 0; j < n[i]; j++) {
            scanf("%lld", &factory[i][j]);
            if (i == 0) factory[i][j] *= b;
            else if (i == 1) factory[i][j] *= k;
            else factory[i][j] *= z;
        }
    }

    for (int i = 0; i < n[0]; i++) {
        for (int j = 0; j < n[1]; j++) {
            bk[bkcnt++] = factory[0][i] + factory[1][j];
        }
    }
    qsort(bk, bkcnt, sizeof(long long), cmp2);
    qsort(factory[2], n[2], sizeof(long long), cmp1);
    best = bk[0] + factory[2][n[2] - 1];
    for (int i = 0; i < n[2]; i++) {
        while (pt < bkcnt && (factory[2][i] + bk[pt]) * 2 > best) pt++;
        r += pt;
    }
    printf("%d", r);
    return 0;
}