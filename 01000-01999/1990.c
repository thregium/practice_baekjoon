#include <stdio.h>

/*
���� : ���� [A, B](A, B <= 10^8)���� �Ӹ�����̸鼭 �Ҽ��� ���� ���� ���Ѵ�.

�ذ� ��� : 10^8 ������ ��� �Ӹ���� �Ҽ��� �̸� ���س��� �����Ѵ�. �����佺�׳׽��� ü�� ���� 10000 ������ ��� �Ҽ����� ���ϰ�
10^8�� ��� �Ӹ���ҿ� ���� �Ҽ� ���θ� ���Ѵ�. �Ӹ������ �Ҽ����� ���� ����س����� �Ǵµ�, 10^8 ������ �Ӹ������ ����
�� 20000�� �����̰�, �� �� �Ҽ��� ���� �׺��� �ξ� ���� ������ �� �� �ִ�. ����, 10000 ������ �Ҽ��� �� 1000�����̹Ƿ�
����� �ð� �� Ǯ �� �ִ� ���̴�. �Ӹ���� �Ҽ��� ���� ���� �������� ���� ���� �ִ� �Ӹ���� �Ҽ��� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : 
*/

int sieve[10240], primes[1280], palp[1024], b10[8] = {1, 10, 100, 1000, 10000, };
int pp = 0, lp = 0;

int rev(int n, int p) {
    int r = 0;
    if (p) n -= n % 10;
    while (n) {
        r *= 10;
        r += n % 10;
        n /= 10;
    }
    return r;
}

void track(int n) {
    int pal, com;
    for (int i = b10[((n + 1) >> 1) - 1]; i < b10[(n + 1) >> 1]; i++) {
        if (i == 1 && n == 1) continue;
        pal = i * b10[n >> 1] + rev(i, n & 1);
        com = 0;
        for (int i = 0; i < pp; i++) {
            if (pal == primes[i]) break;
            else if (pal % primes[i] == 0) {
                com = 1;
                break;
            }
        }
        if (com) continue;
        palp[lp++] = pal;
    }
}

int main(void) {
    for (int i = 2; i <= 10000; i++) {
        if (primes[i]) continue;
        primes[pp++] = i;
        for (int j = i * 2; j <= 10000; j += i) {
            primes[j] = 1;
        }
    }
    for (int i = 1; i < 9; i++) {
        track(i);
    }
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < lp; i++) {
        if (palp[i] < a) continue;
        if (palp[i] > b) break;
        printf("%d\n", palp[i]);
    }
    printf("-1");
    return 0;
}