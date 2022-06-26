#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^8)�� K(K <= 10000)���� �Ҽ��� ���� �� �ִ� �� ���θ� ���Ѵ�.

�ذ� ��� : 4 �̻��� ��� ¦���� �� �Ҽ��� ���� �̿��� ǥ���� �� �ִٴ� �������� ������ �̿��Ѵ�.
��������� �ʾ����� 10^8 �̳��� ��� �ڿ����� ���� �������� Ȯ�εǾ���.
2�� �̻��� �Ҽ��� ¦���� ���鵵�� �ٲ� �� ���� ��쿡�� �Ҽ� ������ ���� ������ �� ���θ� Ȯ���Ѵ�.
�� �ܿ��� �׷��� �ٲ� ���� 4 ������ ���� ������ �Ұ����ϰ�,
�� �ܿ��� ��� ����� ���� �õ��غ��� �ȴ�.

�ֿ� �˰��� : ����, ������, �������� ����, ���̽� ��ũ

��ó : kimyeonwoo0506
*/

int isprime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    int n, k, r = 0;
    scanf("%d %d", &n, &k);
    if (k == 1) {
        if (isprime(n)) printf("%d", n);
        else printf("-1");
    }
    else if (k == 2) {
        if (n & 1) {
            if (isprime(n - 2)) printf("%d %d", 2, n - 2);
            else printf("-1");
        }
        else if (n == 4) printf("2 2");
        else {
            for (int i = 3; i <= n - i; i += 2) {
                if (isprime(i) & isprime(n - i)) {
                    printf("%d %d", i, n - i);
                    r = 1;
                    break;
                }
            }
            if (!r) return 1;
        }
    }
    else {
        if (n & 1) n -= (k - 2) * 2;
        else n -= (k - 2) * 2;
        if (n < 4) printf("-1");
        else {
            for (int i = 2; i < k; i++) {
                if ((n & 1) && i == k - 1) {
                    printf("3 ");
                    n--;
                }
                else printf("2 ");
            }
            if (n & 1) return 2;
            if (n == 4) printf("2 2");
            else {
                for (int i = 3; i <= n - i; i += 2) {
                    if (isprime(i) & isprime(n - i)) {
                        printf("%d %d", i, n - i);
                        r = 1;
                        break;
                    }
                }
                if (!r) return 1;
            }
        }
    }
    return 0;
}