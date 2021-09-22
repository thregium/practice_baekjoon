#include <stdio.h>

/*
���� : N(N <= 5000)���� ������ �̷���� ������ �־��� ��, ���� �� �����ϴ� �κм����� ���̸� ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� ���� �ذ��� �� �ִ�. �� ���� ���� ���� ���̸� ������ ����,
���� ������ ���� ���� ���� ��� ���� ���̰� �� ������ �ڿ� ���̸� �ȴ�.

�ֿ� �˰��� : DP

��ó : USACO 2006X 5��
*/

int cows[5120], mem[5120];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cows[i]);
    }
    for (int i = 1; i <= n; i++) {
        mem[i] = 1;
        for (int j = 1; j < i; j++) {
            if (cows[j] < cows[i] && mem[j] + 1 > mem[i]) mem[i] = mem[j] + 1;
        }
        if (mem[i] > r) r = mem[i];
    }
    printf("%d", r);
    return 0;
}