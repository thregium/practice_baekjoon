#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ����(|| <= 100000)�� ���ϰų� ���� ���� ����� ������ �� ���Ѵ�.
0���� ������ ���� �־����� �ʴ´�.

�ذ� ��� : ��� ������ ���μ������Ͽ� ���ϴ� ��� �� �Ҽ��� ������ ���ϰ�,
������ ��� �������� ����. �̸� �ݺ��� ���� ��� ���� �Ҽ� ������ 0 �̻��� ��� �����̰�,
������ ���� �ϳ��� �ִٸ� ������ �ƴ��� �� �� �ִ�. ��, 0�� �� ���̶� ���� ���
���� 0�̱� ������ �Ҽ� ���� �� ������ ���� �ִ��� ���� �����̴�.

�ֿ� �˰��� : ����, ���μ�����

��ó : ������ 2020M D��
*/

int prime[10240], pcnt[10240], sieve[103000];
int pp = 0;

void factorize(int x, int m) {
    for (int i = 0; prime[i] * prime[i] <= x && i < pp; i++) {
        while (x % prime[i] == 0) {
            pcnt[i] += m;
            x /= prime[i];
        }
    }
    for (int i = pp - 1; i >= 0; i--) {
        if (prime[i] == x) {
            pcnt[i] += m;
            return;
        }
    }
}

int main(void) {
    int n, m, o = 1, z = 0, r = 1;
    char c;
    for (int i = 2; i <= 100000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 100000; j += i) sieve[j] = 1;
    }
    scanf("%d", &n);
    scanf("%d", &m);
    if (m) factorize(abs(m), o);
    else z = 1;
    for (int i = 1; i < n; i++) {
        scanf(" %c", &c);
        scanf("%d", &m);
        if (c == '*') o = 1;
        else o = -1;
        if (m) factorize(abs(m), o);
        else z = 1;
    }
    if (z) printf("mint chocolate");
    else {
        for (int i = 0; i < pp; i++) {
            if (pcnt[i] < 0) r = 0;
        }
        printf("%s", r ? "mint chocolate" : "toothpaste");
    }
    return 0;
}