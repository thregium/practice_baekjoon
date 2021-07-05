#include <stdio.h>

/*
���� : N(N <= 10^6)������ �ڿ����� ��� 4�� 7������ �̷���� ���� ū ���� ���Ѵ�.

�ذ� ��� : N ������ ��� ���� ���� 4�� 7�θ� �̷���� �ִ� ���� �ִ��� Ȯ���Ѵ�. Ȯ���� 10���� ��������
�ڸ������� ���캸�� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����
*/

int isk(int n) {
    int num[9] = {0, };
    int i;
    for (i = 0; n; i++) {
        num[i] = n % 10;
        n /= 10;
    }
    for (int j = 0; j < i; j++) {
        if (num[j] != 4 && num[j] != 7) return 0;
    }
    return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (1) {
        if (isk(n)) {
            printf("%d", n);
            break;
        }
        n--;
    }
    return 0;
}