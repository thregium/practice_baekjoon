#include <stdio.h>

/*
���� : N(N <= 100)���� �ڿ��� ������ X_i, Y_i(X_i, Y_i <= 1000)�� �־��� ��, ���� Y = ax + b�� ����
���� RSS�� ���� a, b�� ���Ѵ�. �׷��� ���� ���� ���� ���� �־����� �ʴ´�.
A�� B�� 1 �̻� 100 ������ �ڿ����̴�.

�ذ� ��� : ��� ������ A, B�� ���� RSS�� ���غ� ���� ���� ���� ���� A, B�� ���ϸ� �ȴ�.
RSS�� ���� �� �����÷ΰ� ���� �ʵ��� �����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : �泲�� 1ȸ F��
*/

int wrk[128][2];

long long f(int x, int a, int b) {
    return (long long)a * x + b;
}

long long sqr(long long x) {
    return x * x;
}

int main(void) {
    int n, ba = -1, bb = -1;
    long long rss = 0, best = (1LL << 60);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wrk[i][0], &wrk[i][1]);
    }
    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            rss = 0;
            for (int i = 0; i < n; i++) {
                rss += sqr(wrk[i][1] - f(wrk[i][0], a, b));
            }
            if (rss < best) {
                best = rss;
                ba = a;
                bb = b;
            }
        }
    }
    if (ba < 0) return 1;
    printf("%d %d", ba, bb);
    return 0;
}