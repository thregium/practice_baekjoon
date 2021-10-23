#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ������ 1500 �̻� 2500 ������ ������� �̷���� �� �迭�� �־�����.
�̶�, �� �迭���� ������ ������ �ٸ� �迭���� ������ �ش� ������ ���� ���� ¦�� ���� �� �ְ�,
����� ������ �ٸ� �迭���� ������ �ش� ������ ū ���� ¦�� ���� �� ���� ��, ������ ���� ¦�� ���� �� �ִ� ���� �ִ���
���� ������� ���� ���� ���� ���Ѵ�.

�ذ� ��� : ������ ���� ¦�� ���� �� �ֱ� ���ؼ� �� ���� ���� �����̰� �ٸ� �� ���� ���� ������� �Ѵ�.
����, ���� ���� �迭�� ���� ¦�� ���� �� �ִ� �ֳ��� ������ ����� ������ �Է¹޴´�.
�� ����, �� �迭�� �����ϰ�, ���� �� �ִ� ¦�� ���� Ȯ���Ѵ�. ���� �� �ִ� ¦�� ���� ���� �� ���� �迭�� Ȯ���ϸ鼭
�ش� ������ ū �� ��� ���� ���� ���� Ȯ���ϴ� ������ ���� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, �� ������

��ó : COCI 11/12#1 4��
*/

int mf[2][103000], fm[2][103000];
int mfs[2], fms[2];

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

int main(void) {
    int n, x, r = 0, p = 0;
    //freopen("E:\\PS\\Contest\\COCI\\11-12\\contest1_testdata\\ples\\ples.in.10a", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > 0) mf[0][mfs[0]++] = x;
        else fm[0][fms[0]++] = -x;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x < 0) mf[1][mfs[1]++] = -x;
        else fm[1][fms[1]++] = x;
    }
    qsort(mf[0], mfs[0], sizeof(int), cmp1);
    qsort(mf[1], mfs[1], sizeof(int), cmp1);
    qsort(fm[0], fms[0], sizeof(int), cmp1);
    qsort(fm[1], fms[1], sizeof(int), cmp1);

    for (int i = 0; i < mfs[0]; i++) {
        while (p < mfs[1] && mf[0][i] >= mf[1][p]) p++;
        if (p++ < mfs[1]) r++;
        else break;
    }
    p = 0;
    for (int i = 0; i < fms[1]; i++) {
        while (p < fms[0] && fm[1][i] >= fm[0][p]) p++;
        if (p++ < fms[0]) r++;
        else break;
    }
    printf("%d", r);
    return 0;
}
