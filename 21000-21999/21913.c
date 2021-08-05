#include <stdio.h>
#define MOD 1000000007

/*
���� : 1���� N(N <= 10^6)������ �ڿ����� �̷���� ���� ��� ������ �� ���� �������� ���� 2 ������ ������ ���� ���Ѵ�.

�ذ� ��� : �߰� ����

�ֿ� �˰��� : DP, ������

��ó : SEERC 2020 I��
*/

int perms[1048576];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    if (n <= 3) {
        printf("%d", n == 1 ? 1 : n == 2 ? 2 : 6);
        return 0;
    }
    perms[n - 1] = 1;
    for (int i = n - 2; i > 2; i--) {
        perms[i] = perms[i + 1] + 1;
        for (int j = i * 2 - 1; j < n; j += i) {
            perms[i] = ((long long)perms[i] + perms[j] + perms[j + 1] + perms[j + 2]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        r = (r + perms[i]) % MOD;
    }
    printf("%lld", (long long)r * n * 2 % MOD);
    return 0;
}