#include <stdio.h>

/*
���� : 1 / 2 + 1 / 3 + ... + 1 / (n + 1)�� S(S <= 5.2) �̻��� �Ǵ� ���� ���� N�� ���Ѵ�.

�ذ� ��� : 1 / 2���� ���ʷ� ���ذ��� S �̻��� �Ǵ� ���� ������ ���� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : MidC 2001 E��
*/

int main(void) {
    double s, x;
    int i;
    while (1) {
        scanf("%lf", &s);
        if (s < 0.001) break;
        x = 0.0;
        for (i = 1; x < s; i++) {
            x += 1.0 / (i + 1.0);
        }
        printf("%d card(s)\n", i - 1);
    }
    return 0;
}