#include <stdio.h>

/*
���� : �� ���� ���� N(N <= 10^9)�� �������� ���� ���Ѵ�.

�ذ� ��� : 1���� sqrt(N)������ ���� Ȯ���ϸ� N�� ���� �� �ִ� ����� sqrt(N)�� ��� �ᱣ���� 1�� ���ϰ�
�� ���� ��� �ᱣ���� 2�� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������
*/

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue;
        if (i * i == n) r++;
        else r += 2;
    }
    printf("%d", r);
    return 0;
}