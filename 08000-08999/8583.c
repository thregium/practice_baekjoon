#include <stdio.h>

/*
���� : [A, B](A <= B <= 10^18) �������� ��� ���λ簡 �Ҽ��� ���� ������ ���Ѵ�.

�ذ� ��� : ���� ��Ʈ��ŷ�� �غ��� �׷��� ���� ��� ���� ���������� ���´ٴ� ���� �� �� �ִ�.
����, ��Ʈ��ŷ�� �� ��, ��� ���ǿ� �´� ���� Ȯ���ϸ鼭 ���� �ȿ� �ִ� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : ����, �Ҽ� ����, ��Ʈ��ŷ

��ó : JPOI 2011 1-2��
*/

long long res[128];
int rcnt = 0;

int isprime(long long x) {
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void track(int n, long long p) {
    if (n == 18) return;
    if (!isprime(p)) return;
    res[rcnt++] = p;
    track(n + 1, p * 10 + 1);
    track(n + 1, p * 10 + 3);
    track(n + 1, p * 10 + 7);
    track(n + 1, p * 10 + 9);
}

int main(void) {
    track(1, 2);
    track(1, 3);
    track(1, 5);
    track(1, 7);
    long long a, b, r = 0;
    scanf("%lld %lld", &a, &b);
    for (int i = 0; i < rcnt; i++) {
        if (a <= res[i] && res[i] <= b) r++;
    }
    printf("%lld", r);
    return 0;
}