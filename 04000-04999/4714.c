#include <stdio.h>

/*
���� : �������� ���� X�� ������ �޿����� ���԰� ������ ���Ѵ�. ���� �߷��� ���� �߷��� 0.167���̴�.

�ذ� ��� : X�� 0.167�踦 ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : MidAt 2010 P��
*/

int main(void) {
    double x;
    while (1) {
        scanf("%lf", &x);
        if (x < -0.5) break;
        printf("Objects weighing %.2f on Earth will weigh %.2f on the moon.\n", x, x * 0.167);
    }
    return 0;
}