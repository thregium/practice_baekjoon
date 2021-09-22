#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^9)�� �־��� ��, N�� �� �ڸ����� ������ ���� ���ϴ� ���� �ݺ��ϸ� �׻� 1�� �ǰų�,
4�� �����ϴ� �ݺ��������� �����ϴ� ���� ����Ǿ���. N�� ��� �ʿ� ������ ���Ѵ�.

�ذ� ��� : �ùķ��̼��� ���� N�� 1 �Ǵ� 4�� �� �� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : Daejeon 2017 D��
*/

int main(void) {
    long long n, t;
    scanf("%lld", &n);
    while (1) {
        t = 0;
        for (long long i = n; i; i /= 10) {
            t += (i % 10) * (i % 10);
        }
        n = t;
        if (n == 4) {
            printf("UNHAPPY");
            break;
        }
        else if (n == 1) {
            printf("HAPPY");
            break;
        }
    }
    return 0;
}