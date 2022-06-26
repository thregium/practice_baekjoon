#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 1000)���� ������� �꿡 �ö�´�. �� ����� ���� ������ų �� p_i��ŭ ���� ������Ű��,
c_i(p_i, c_i <= 3000) �̻� ���� �����Ǹ� ������ �ʴ´�. �̶�, �ʱ� �������� 0�� ���
���� ���� �� �ִ� ����� �ִ� ���� ���Ѵ�.

�ذ� ��� : ci + pi ������� �� ����� ���� ������ ������ ����(���ð� �� �� ���� �������� ��������),
�� ������ �������� ���̳��� ���α׷����� ���� N���� ����� ���� ���� �� �������� ����
�ִ� �ο����� ���ϰ� �� ��� �ִ��� ����ϸ� �ȴ�. p_i + c_i�� �ִ� - 1����
���� ���� �� �ִٴ� ���� �����Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, DP, ����

��ó : ������ 2022H H��
*/

int pc[1024][2], mem[1024][6144];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1) + *((int*)a);
    int bi = *((int*)b + 1) + *((int*)b);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, res = -INF, rn = -1;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 6000; j++) mem[i][j] = -INF;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &pc[i][0], &pc[i][1]);
    }
    qsort(pc + 1, n, sizeof(int) * 2, cmp1);
    mem[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 6000; j++) {
            if (mem[i][j] < 0) continue;
            if (mem[i][j] > mem[i + 1][j]) mem[i + 1][j] = mem[i][j];
            if (j < pc[i + 1][1] && j + pc[i + 1][0] <= 6000 &&
                mem[i][j] + 1 > mem[i + 1][j + pc[i + 1][0]]) {
                mem[i + 1][j + pc[i + 1][0]] = mem[i][j] + 1;
            }
        }
    }
    for (int i = 0; i <= 6000; i++) {
        if (mem[n][i] > res) {
            res = mem[n][i];
            rn = i;
        }
    }
    if (res < 0) return 1;
    printf("%d %d", res, rn);
    return 0;
}