#include <stdio.h>

/*
���� : N(N <= 10^6)!�� �������� ���� 0�� ������ ���Ѵ�.

�ذ� ��� : N!�� �����ϴ� 5�� ������ ����.

�ֿ� �˰��� : ����, ������

��ó : Khawarizmi 2013 A��
*/

int main(void) {
    int n, r;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 0;
        for (int i = n / 5; i; i /= 5) r += i;
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}
