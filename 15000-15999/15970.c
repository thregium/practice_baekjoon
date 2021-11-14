#include <stdio.h>
#include <stdlib.h>

/*
���� : �������� N(N <= 5000)���� ���� �ְ�, �� ������ N�� ������ ������ ��ȣ�� ���� �ִ�.
�� ������ ���� ���� ���� ����� �������� �Ÿ��� ���� ���Ѵ�. ��, ��� ������ ���� ���� ���� �ݵ�� �����Ѵ�.

�ذ� ��� : ������ ���󺰷� �з��� ����, ������ �����Ѵ�. �׸��� �� �� �� ���� �Ÿ� ��� �� ����� ���� �Ź� �����ϰ�
�װ������� �Ÿ��� ���� ���س����� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : ���� 2018 ��2��
*/

int dot[5120][5120];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, y, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        dot[y][++dot[y][0]] = x;
    }
    for (int i = 1; i <= n; i++) {
        if (dot[i][0] == 1) return 1;
        else if (dot[i][0] == 0) continue;
        qsort(&dot[i][1], dot[i][0], sizeof(int), cmp1);
        for (int j = 1; j <= dot[i][0]; j++) {
            if (j == 1) r += dot[i][j + 1] - dot[i][j];
            else if (j == dot[i][0]) r += dot[i][j] - dot[i][j - 1];
            else {
                r += small(dot[i][j] - dot[i][j - 1], dot[i][j + 1] - dot[i][j]);
            }
        }
    }
    printf("%d", r);
    return 0;
}