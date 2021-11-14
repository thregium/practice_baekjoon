#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ������ �־�����, ���ΰ� ������ ������ �־�����. �׸��� ����� �� ������ Į�θ��� �־�����,
���� ���� ��� Į�θ��� ���� ���� ���� ��� Į�θ��� ���Ѵ�. ������ �� ������ �� ������ �ø� �� �ְ�, �� ���� �ø� �� �ִ�.

�ذ� ��� : ��� ������ ������ ���� ������ Į�θ��� ���� �� ���� �ø��� ���� �̵��̴�.
Į�θ� ���� ������������ ������ ����, ��� ������ �÷����� ���� ���� ��� Į�θ��� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����, ����

��ó : JOI 2012�� 3��
*/

int cal[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, a, b, d, bestc = 0, bestp = 0, nowc = 0, nowp = 0;
    scanf("%d", &n);
    scanf("%d %d%d", &a, &b, &d);
    bestc = d, bestp = a, nowc = d, nowp = a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &cal[i]);
    }
    qsort(cal, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        nowc += cal[i];
        nowp += b;
        if ((long long)nowc * bestp > (long long)bestc * nowp) {
            bestc = nowc;
            bestp = nowp;
        }
    }
    printf("%d", bestc / bestp);
    return 0;
}