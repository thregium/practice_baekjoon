#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� ��ġ�� ������������ ��ġ, ���� 1�� �ɾ ���� ���������Ͱ� ������ ���� ���� �ð���
�־��� ��, ���� 0���� ���� �� �ɸ��� �ּ� �ð��� ���Ѵ�.

�ذ� ��� : ��� ĭ�� �ɾ�� �Ͱ� ���������͸� ��ٸ��� ��, ������������ ��ġ����
�̵��� ���� Ÿ�� �� 3������ ��츦 ���ؼ� ���� ���� ���� Ÿ�� �ȴ�. �߰����� ��ư�� ������ ����
�ǹ̰� �����Ƿ� �������� �ʾƵ� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : CTU 2021 I��
*/

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    long long t, yp, lp, ys, ls, a, b, c;
    scanf("%lld", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %lld %lld %lld", &yp, &lp, &ys, &ls);
        a = yp * ys;
        b = (yp + abs(yp - lp)) * ls;
        c = abs(yp - lp) * ys + lp * ls;
        printf("%lld\n", small(a, small(b, c)));
    }
    return 0;
}