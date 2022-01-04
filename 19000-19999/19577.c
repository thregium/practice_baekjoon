#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^9)�� �־��� ��, x * phi(x) == N�� �����ϴ� ���� ���� X�� ã�´�.
�׷��� ���� ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : sqrt(N) �̻��� N�� ��� ����� ���� phi(x)�� ���� ������ �̿��Ͽ� ���� ����,
X�� ���Ͽ� N�� ������ ���� ���� X�� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, ���Ϸ� �� �Լ�, ���� ����, ���Ʈ ����

��ó : SUAPC 2020S1 I��
*/

int div[256], pri[64], odd[103000], even[103000];

long long phi(int n) {
    long long r = 0, m = n;
    int pp = 0, op = 0, ep = 0, c, x;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            pri[pp++] = i;
        }
    }
    if (n > 1) pri[pp++] = n;
    for (int i = 0; i < (1 << pp); i++) {
        x = 1, c = 0;
        for (int j = 0; j < pp; j++) {
            if ((i >> j) & 1) {
                c++;
                x *= pri[j];
            }
        }
        if (c & 1) odd[op++] = x;
        else even[ep++] = x;
    }
    
    for (int i = 0; i < op; i++) {
        r -= m / odd[i];
    }
    for (int i = 0; i < ep; i++) {
        r += m / even[i];
    }

    return r;
}

int main(void) {
    int n, c = 0, r = -1;
    scanf("%d", &n);
    
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) div[c++] = n / i;
    }
    for (int i = 0; i < c; i++) {
        if (div[i] * phi(div[i]) == n) r = div[i];
    }
    
    printf("%d", r);
    return 0;
}