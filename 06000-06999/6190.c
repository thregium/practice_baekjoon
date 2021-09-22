#include <stdio.h>

/*
���� : N(N <= 10^6)���� �����ϴ� �ݶ��� ������ ���̸� ���Ѵ�.

�ذ� ��� : 1�� �� �� ���� �ݺ��ϸ� �ݺ� Ƚ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : USACO 2006X G1��
*/

int main(void) {
    long long n, score = 0;
    scanf("%lld", &n);
    while (n > 1) {
        if (n & 1) n = n * 3 + 1;
        else n >>= 1;
        score++;
    }
    printf("%lld", score);
    return 0;
}