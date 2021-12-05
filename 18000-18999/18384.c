#include <stdio.h>

/*
���� : 5���� �ڿ���(<= 10^6)�� �־��� ��, �� �ش� �� �̻��� ���� ���� �Ҽ��� ���� ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��� �̸� 10^6 ���� �Ҽ������� �Ҽ� ���θ� ���� ���س��´�.
�� �� ������ �Է¹����� �� ������ �� �� �̻����� �ö󰡸� ������ ù �Ҽ����� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �����佺�׳׽�

��ó : Kabul 2018 C��
*/

char sieve[1048576];

int main(void) {
    int t, x, r = 0;
    for (int i = 2; i < 1048576; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j < 1048576; j += i) sieve[j] = 1;
    }
    sieve[1] = 1;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        r = 0;
        for (int i = 0; i < 5; i++) {
            scanf("%d", &x);
            for (int j = x;; j++) {
                if (!sieve[j]) {
                    r += j;
                    break;
                }
            }
        }
        printf("%d\n", r);
    }
    return 0;
}