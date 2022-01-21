#include <stdio.h>

/*
���� : �ڿ��� M(4 <= M <= 100000), A, B(1 <= A <= B <= 1000)�� �־��� ��,
���� M ���ϸ� ������ ������ A / B �̻� 1 ������ �� �Ҽ� �� P, Q ��� ������ ���� ���� ū ���� ���Ѵ�.

�ذ� ��� : M�� ������ ũ�� �����Ƿ� ���� �����佺�׳׽��� ü�� �̿��� 100000 ������ ��� �Ҽ��� ����
��ó���Ѵ�. �׸��� ���Ʈ ������ ���� P * Q�� M �̳��� ������ ���ϸ� O(MlogM)�� �ð� ����
��� ������ ���� �� �ְ�, �Ҽ��鸸 ���µ��� A / B �̻����� ���� ������ ���鵵 ���ܵǱ� ������
�����δ� �ſ� ������ ���� ���� �� �ִ�.

�ֿ� �˰��� : ����, �����佺�׳׽�, ���Ʈ ����

��ó : Kanazawa 2002 A��
*/

char sieve[103000];
int prime[16384];
int pp = 0;

int main(void) {
    int m, a, b, ba, bb;
    long long best;
    for (int i = 2; i <= 100000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 100000; j += i) sieve[j] = 1;
    }
    while (1) {
        scanf("%d %d %d", &m, &a, &b);
        if (m == 0) break;

        best = 0, ba = -1, bb = -1;
        for (int i = 0; i < pp; i++) {
            if (prime[i] > m) break;
            for (int j = i; j < pp; j++) {
                if ((long long)prime[i] * prime[j] > m || prime[i] * b < prime[j] * a) break;
                if ((long long)prime[i] * prime[j] > best) {
                    best = (long long)prime[i] * prime[j];
                    ba = prime[i], bb = prime[j];
                }
            }
        }
        if (ba < 0) return 1;
        printf("%d %d\n", ba, bb);
    }
    return 0;
}