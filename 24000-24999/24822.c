#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ����� �ִ� ��ġ�� M(M <= 100)�׷��� ������ �ִ� ��ġ�� ����������
�ڿ��� ��(<= 1000)���� �־�����. ��� �Ǵ� ������ ��ġ������ �ߺ����� �ʴ´�.
����� ���� ����� ���� ��� ���� ���ʿ� �ִ� ������ �̵��Ѵ�. �� ������ 1���� ����� ������ �� �ִٸ�
������ ������ �� ���� ����� ���� ���Ѵ�.

�ذ� ��� : �� ����� �����ϴ� �������� �迭�� ������ ����, �����ϰ� �ߺ����� �ʴ� ������ ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����, ����

��ó : VTH 2019 E��
*/

int p[128], t[128], sel[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < n; i++) {
        sel[i] = 103000;
        for (int j = 0; j < m; j++) {
            if (abs(p[i] - t[j]) < abs(p[i] - sel[i]) ||
                (abs(p[i] - t[j]) == abs(p[i] - sel[i]) && t[j] < sel[i])) sel[i] = t[j];
        }
    }
    qsort(sel, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (sel[i] != sel[i + 1]) r++;
    }
    printf("%d", n - r);
    return 0;
}