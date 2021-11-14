#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ������ ���� ���̿� ����, ���̰� �־�����. ���̿� ���Դ� ���� ��� �ٸ���, ���̿� ���԰�
�����ϴ� ������ ������ ���� �� ���̰� ���� ������ ������ �״� ����� ����Ѵ�.

�ذ� ��� : �� ������ ���̿� ���� ������������ ������ ����, �� ��°�� ������ ���� ���� ������ ���� �� ���ſ�
�͵� ��� ���� ���̰� ���� ���� �������� DP�� �����Ѵ�. ���� ���� ����,
���� ���̰� ���� �� ���� �������� ����� ã�Ƴ����� �ȴ�.

�ֿ� �˰��� : DP, ������, ����

��ó : ���� 1998 ��3��
*/

int brick[128][4], mem[128], last[128], build[128];

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0, p;
    scanf("%d", &n);
    brick[0][0] = 103000, brick[0][2] = 103000;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &brick[i][0], &brick[i][1], &brick[i][2]);
        brick[i][3] = i;
    }
    qsort(brick + 1, n, sizeof(int) * 4, cmp1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (brick[j][2] > brick[i][2]) {
                if (mem[j] + brick[i][1] > mem[i]) {
                    mem[i] = mem[j] + brick[i][1];
                }
            }
        }
    }

    p = 0;
    for (int i = 1; i <= n; i++) {
        if (mem[i] > mem[p]) p = i;
    }
    while (mem[p]) {
        build[r++] = brick[p][3];
        if (r > 1 && build[r - 1] == build[r - 2]) return 1;
        for (int i = p - 1; i >= 0; i--) {
            if (mem[i] + brick[p][1] == mem[p] && brick[i][2] > brick[p][2]) {
                p = i;
                break;
            }
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%d\n", build[i]);
    }
    return 0;
}