#include <stdio.h>
#include <math.h>

/*
���� : �Ÿ� M(M <= 10000) km�� A km / h�� �� ���� B(0 < A < B <= 1000) km / h�� �� �� �ɸ��� �ð���
�� ������ �ݿø��Ͽ� ����Ѵ�.

�ذ� ��� : A�� �� �� �ɸ��� �ð��� M / A�̰�, B�δ� M / B�̴�. M / A�� �� ũ�Ƿ� M / A - M / B�� ���� ����,
3600�� ���ϸ� �ɸ��� �ʰ� �ǰ�, round()�Լ��� �̿��� �ݿø��� ����, ��, ��, �ʸ� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : SEUSA 2013D2 I��
*/

int main(void) {
    int m, a, b, r;
    //freopen("E:\\PS\\ICPC\\North America\\Southeast USA\\2013\\speed.judge", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Southeast USA\\2013\\speed.out", "w", stdout);
    while (1) {
        scanf("%d %d %d", &m, &a, &b);
        if (m == 0) break;
        r = round(((double)m / a - (double)m / b) * 3600 + 0.000001);
        printf("%d:%02d:%02d\n", r / 3600, r / 60 % 60, r % 60);
    }
    return 0;
}