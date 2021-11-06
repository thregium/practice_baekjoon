#include <stdio.h>
#include <stdlib.h>

/*
���� : M(M <= 1000)���� ������ ���� �ش� ������ �������� ����(<= N)�� �־�����, �� ������ ��ġ(<= 10^6)�� �־�����.
N�� 10^6 ������ �ڿ����̴�. �������� R(R < N)��ŭ�� ������ �ΰ� �������� ��ġ�� �ʰ� �������� ��
��ġ�� ���� �ִ��� ���Ѵ�.

�ذ� ��� : �� �������� ������ ������ �����Ѵ�. �׸��� dp(x)�� �ð� x���� ���� �ִ����� �����ϰ� ���̳��� ���α׷����� �Ѵ�.
����, dp(0)�� 0���� �ΰ�, ���ķδ� dp(x)�� dp(x - 1)�� dp(x) ��� �� ū ������ �����Ѵ�.
�Ź� x�� �����ϴ� �����鸶�� dp(e + r)�� dp(x) + h�� ���� ū ������ �����Ѵ�.(e�� �ش� ������ ����, h�� ��ġ)
�̸� �ݺ��� �� dp(n + r)�� ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : DP, ����

��ó : USACO 2007N S2��
*/

int milk[1024][3], mem[2097152];

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, r, p = 0;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &milk[i][0], &milk[i][1], &milk[i][2]);
    }
    qsort(milk, m, sizeof(int) * 3, cmp1);
    for (int i = 0; i <= n + r; i++) {
        if (i > 0) mem[i] = big(mem[i - 1], mem[i]);
        while (p < m && milk[p][0] == i) {
            mem[milk[p][1] + r] = big(mem[milk[p][1] + r], mem[i] + milk[p][2]);
            p++;
        }
    }
    printf("%d", mem[n + r]);
    return 0;
}