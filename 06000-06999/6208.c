#include <stdio.h>
#include <stdlib.h>

/*
���� : ��ü ���� L(L <= 1000)�� �־�����, N(N <= 10000)���� ���� 1 �̻��� ������ �־��� ��, ���� B(B <= 1000)��
���� ������ ���� L�� ��ġ�� �ʰ� ��� �����ϴ� ������ ���� ��� ���� ��ġ(<= 10^6)�� ���� ū ���� ���Ѵ�.
�׷��� ���� ���� ��� -1�� ����Ѵ�.

�ذ� ��� : ���� �� ������ ���� ���� ���� ������� �����Ѵ�. �� ����, ���� X���� ���� Y�� ������� ����
��ġ �� �ִ��� �������� DP�� �Ѵ�. �̶�, 0, 0�� ���� ������ �������� -1(�׷��� ���� ����)�� �ʱ�ȭ�� �д�.
�� �ķδ� �� ������ ���� ������ ������ ��� ������ ����([0, B - C_i])���� mem(X, Y) + F_i�� mem(X + w_i, Y + C_i)����
�� ū ��� ���Ž�Ű�� ���� �ݺ��Ѵ�. ��, mem(X, Y)�� -1�� ���� �������� �ʰ� �Ѿ��.
�� �۾��� ������ ���� L���� ��� ���� ���� �� ���� mem(L, i)�� ���� ū ���� ��� ����ϸ� �ȴ�.
�׷��� ���� ���ٸ� �ڵ����� -1�� �� ���̴�.

�ֿ� �˰��� : DP, ����

��ó : USACO 2006D S2��
*/

int roller[10240][4], mem[1024][1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int l, n, b, r = -1;
    scanf("%d %d %d", &l, &n, &b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &roller[i][j]);
        }
    }
    qsort(roller, n, sizeof(int) * 4, cmp1);
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) mem[i][j] = -1;
    }
    mem[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= b - roller[i][3]; j++) {
            if (mem[roller[i][0]][j] < 0) continue;
            else mem[roller[i][0] + roller[i][1]][j + roller[i][3]] = big(mem[roller[i][0] + roller[i][1]][j + roller[i][3]],
                mem[roller[i][0]][j] + roller[i][2]);
        }
    }
    for (int i = 0; i <= b; i++) r = big(r, mem[l][i]);
    printf("%d", r);
    return 0;
}