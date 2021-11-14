#include <stdio.h>

/*
���� : �ڿ��� N(N < 1000)�� �־��� ��, (1, 1)���� (N, N)���� �� �� ��� �ϳ��� 1�� �ø��鼭
�� ���� �̾���� ���� �Ҽ��� ��찡 ���� ������ �� �� ������ �Ҽ��� ���� ���Ѵ�. ��, 11�� �����Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��Ͽ� 10^6 ������ �Ҽ����� ���ϰ�, (N, N)���� ž�ٿ� ������� DP�� �����ϸ� �ȴ�.

�ֿ� �˰��� : DP, ����, �����佺�׳׽�

��ó : BtOI 2011 P2��
*/

char sieve[1048576];
int mem[1024][1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int putting(int a, int b) {
    if (b < 10) return a * 10 + b;
    else if (b < 100) return a * 100 + b;
    else if (b < 1000) return a * 1000 + b;
    else return a * 10000 + b;
}

int dp(int x, int y) {
    if (mem[x][y] >= 0) return mem[x][y];
    else if (x == 1 && y == 1) return mem[x][y] = 0;
    int r = 0;
    if (x > 1) r = big(r, dp(x - 1, y));
    if (y > 1) r = big(r, dp(x, y - 1));
    return mem[x][y] = r + (!sieve[putting(x, y)]);
}

int main(void) {
    int n;
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 1;
    }
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) mem[i][j] = -1;
    }
    scanf("%d", &n);
    printf("%d", dp(n, n));
    return 0;
}