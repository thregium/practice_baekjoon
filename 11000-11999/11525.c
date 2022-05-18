#include <stdio.h>

/*
���� : �ڿ��� N(2 <= N <= 10000)�� �־��� ��, (0 <= A <= B <= N, 1 <= B)�� �������� ���� �ٸ� ���м���
�������� ���Ѵ�.

�ذ� ��� : 1�϶��� ���� 2�� �ϰ� �� ���ķδ� ���Ϸ�-�� �Լ��� ���� ���� ������ N�� ���� ���� �ȴ�.
�̸� ���� ���� ���� ���ؼ� ���� ������ ���ϴ� ���� ����.

�ֿ� �˰��� : ����, ������, ���Ϸ�-��

��ó : GNY 2015 D�� // IIPC 2015 D��
*/

int mem[10240], div[256], pri[64], odd[103000], even[103000];

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
    int t, k, n;
    mem[1] = 2;
    for (int i = 2; i <= 10000; i++) {
        mem[i] = phi(i) + mem[i - 1];
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &k, &n);
        printf("%d %d\n", k, mem[n]);
    }
    return 0;
}