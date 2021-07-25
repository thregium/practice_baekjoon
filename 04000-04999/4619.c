#include <stdio.h>
#define INF 1012345678

/*
���� : B(B <= 10^6)�� ���� ����� A^N(N <= 9)�� A ���� ���Ѵ�.

�ذ� ��� : N�� ���̵� �ִ� 100�� ���Ͽ��� ���� ������ ������ A�� 1���� ���ʷ� �ö󰡸� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : MidC 2006 G��
*/

int main(void) {
    int b, n, x, diff, aa;
    while (1) {
        scanf("%d %d", &b, &n);
        if (b == 0 && n == 0) break;
        diff = INF;
        for (int a = 1;; a++) {
            x = 1;
            for (int i = 0; i < n; i++) x *= a;
            if (x > b) {
                if (x - b < diff) printf("%d\n", a);
                else printf("%d\n", a - 1);
                break;
            }
            else diff = b - x;
        }
    }
    return 0;
}