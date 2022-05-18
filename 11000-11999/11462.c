#include <stdio.h>
#include <stdlib.h>

/*
���� : �ڿ��� N(N <= 100000)�� �־��� ��, N���� �����鼭 �ڸ����� ���� N�� �ڸ��� �պ��� 1 ����
�� ��� ���� ū ���� ã�´�.

�ذ� ��� : N�� ������ �����Ƿ� N - 1���� 0���� �ϳ��� Ȯ���ϸ� �ڸ��� ���� N�� �ڸ��� �� - 1�� �Ǵ�
ù ���� ã���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : CTU 2015 O��
*/

char s[16];

int getdigitsum(int x) {
    int r = 0;
    while (x) {
        r += x % 10;
        x /= 10;
    }
    return r;
}

int main(void) {
    int n, sum;
    while (1) {
        scanf("%s", s);
        if (s[0] == 'E') break;
        n = strtoll(s, NULL, 10);
        sum = getdigitsum(n);
        for (int i = n - 1;; i--) {
            if (i < 0) return 1;
            if (getdigitsum(i) == sum - 1) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}