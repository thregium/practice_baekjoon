#include <stdio.h>
#define INF 1234567890987654321

/*
���� : N(N <= 3000)���� ����(|| <= 10^9)�� �־�����. 1��°�� ������ ���� �ݵ�� �����ϰ�,
�� ���� �� ������ ������ �̵� �Ÿ��� ���� �����ؾ� �Ѵٰ� �� ��, ������ ������ ���� �ִ��� ���Ѵ�.

�ذ� ��� : �� (��ġ, �ּ� �̵� �Ÿ�)�� ���·� �Ͽ� �׶��� �ִ��� �����ذ���
���̳��� ���α׷����� �����Ѵ�. �Ź� �ּ� �̵� �Ÿ���ŭ �� ĭ�� ���� �� �Ÿ� �̻��� �ִ���
���ϰ� ���� ��ġ�� ���� ���س����� �ȴ�. �ִ��� ������ ���� ���� ã�ƾ� �ð� ���� ���� �� �ִ�.

�ֿ� �˰��� : DP, ���� ��?

��ó : BAPC 2021 D�� // UKIEPC 2021 D��
*/

int p[3072];
long long mem[3072][3072], cum[3072][3072];

long long big(long long a, long long b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    long long r = -INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < 3072; i++) {
        for (int j = 0; j < 3072; j++) {
            cum[i][j] = -INF;
            mem[i][j] = -INF;
        }
    }
    mem[1][n - 1] = p[1];
    for (int i = 1; i < n; i++) cum[1][i] = p[1];
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {
            mem[i][j] = cum[i - j][j] + p[i];
        }
        for (int j = n - 1; j > 0; j--) {
            cum[i][j] = big(mem[i][j], cum[i][j + 1]);
        }
    }
    for (int i = 1; i < n; i++) {
        if (mem[n][i] > r) r = mem[n][i];
    }
    printf("%lld", r);
    return 0;
}