#include <stdio.h>
#include <math.h>

/*
���� : mx + kp / m�� ���� �ּҰ� �Ǵ� �ڿ��� m�� ���� �ش� ���� ���� ã�´�.

�ذ� ��� : �̺��� ���� ���Լ��� ���� 0�� ���� m ���� ã���� sqrt(kp / x)�� �ȴ�. ����, �� ������ ���� �����
�ڿ����� ���� ���� ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����, ��������

��ó : PacNW 2017 L��/Y��
*/

int main(void) {
    int k, p, x;
    double best = 1E32, m;
    scanf("%d %d %d", &k, &p, &x);
    m = sqrt((double)k * p / x);
    for (int i = (int)(m - 5); i <= (int)(m + 5); i++) {
        if (i < 1) continue;
        if ((double)i * x + (double)k * p / i < best) best = (double)i * x + (double)k * p / i;
    }
    printf("%.3f", best);
    return 0;
}