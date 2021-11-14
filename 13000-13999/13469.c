#include <stdio.h>

/*
���� : N(N <= 10^9)�� �־��� ��, �� ���� �Ҽ��� �ŵ��������� ���Ѵ�.

�ذ� ��� : 1���� sqrt(N)���� Ȯ���ϸ鼭 ������ �������� ���� ������ ���� 1���� ���������� Ȯ���Ѵ�.
1���� �������� �Ҽ��� �ŵ������̰�, �� �ܿ��� �ƴϴ�.

�ֿ� �˰��� : ����, ������, �Ҽ� ����

��ó : BAPC 2016 I��
*/

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("no");
        return 0;
    }
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            if (n == 1) {
                printf("yes");
                return 0;
            }
            else {
                printf("no");
                return 0;
            }
        }
    }
    printf("yes");
    return 0;
}
