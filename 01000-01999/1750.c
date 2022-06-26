#include <stdio.h>
#define MOD 10000003

/*
���� : N(N <= 50)���� �ڿ���(<= 100000)�� �̷���� ������ �������� �ƴ� �κ����� ���
��� ���� �ִ������� 1�� �Ǵ� ������ ������ ���Ѵ�.

�ذ� ��� : �� ���� ���� �� ���� �� ������ Ȯ������ �� �� �ִ��������� ������ ������ ���� �ȴ�.
�� �������� ���̳��� ���α׷��ְ� ��Ŭ���� ȣ������ �̿��ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, DP, ��Ŭ���� ȣ����
*/

int s[64], mem[64][103000];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100000; j++) {
            mem[i][j] = (mem[i][j] + mem[i - 1][j]) % MOD;
            mem[i][gcd(j, s[i])] = (mem[i][gcd(j, s[i])] + mem[i - 1][j]) % MOD;
        }
        mem[i][s[i]] = (mem[i][s[i]] + 1) % MOD;
    }
    printf("%d", mem[n][1]);
    return 0;
}