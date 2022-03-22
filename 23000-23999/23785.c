#include <stdio.h>

/*
���� : �� �ڸ����� ���丮�� ���� N(1 <= N <= 10^9)�� ���� ���� ���� ���Ѵ�.

�ذ� ��� : 1�������� 9������ �ڸ����� ���� 1! ~ 9!�� �Ͽ� ���� ���� ���� �� �������
������ ����ŭ �� �ڸ����� ����� ������ �ȴ�. N�� 1�� ���� ���� 0�ӿ� �����Ѵ�.

�ֿ� �˰��� : ����, ������, �׸��� �˰���

��ó : CTU 2021 O��
*/

int fact[16], res[16];

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    fact[0] = 1;
    for (int i = 1; i <= 9; i++) fact[i] = fact[i - 1] * i;
    for (int i = 9; i >= 1; i--) {
        res[i] = n / fact[i];
        n %= fact[i];
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < res[i]; j++) printf("%d", i);
    }
    return 0;
}