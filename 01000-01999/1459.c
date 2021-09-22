#include <stdio.h>
#include <stdlib.h>

/*
���� : (0, 0)���� (X, Y)(X, Y <= 10^9)�� �̵��Ϸ� �Ѵ�. �����¿�� 1��ŭ �̵��ϴµ����� W,
�밢������ (1, 1)��ŭ �̵��ϴµ����� S��ŭ �ð��� ��ٸ� �̵��ϴµ� �ɸ��� �ּ� �ð��� ���Ѵ�.

�ذ� ��� : �밢������ �̵��ϴ� �ð��� ���� ��츦 ������ �ذ��Ѵ�. ���� 2ĭ �̵��ϴ� �ð����� ũ�ٸ�
�����¿�θ� �̵��ϴ� ���� �̵��̴�. 1ĭ �̵��ϴ� �ð��� 2ĭ �̵��ϴ� �ð� ������ ��쿡��
�Ÿ��� ���̴� ��쿡�� �밢�� �̵��� �̵��̰� �� �ܿ��� �����¿� �̵��� �̵��̴�.
1ĭ �̵��ϴ� �ð����ٵ� ���� ��쿡�� �ִ��� �밢�� �̵��ϴ� ���� �̵��̴�. ������ Ȧ¦���� �ٸ� ĭ�� ��쿡��
�밢�� �̵������� ���� �Ұ����ϹǷ� 1ĭ�� �����¿�� �̵��ؾ� �Ѵ�.

�ֿ� �˰��� : ������, ���̽� ��ũ
*/

long long big(long long a, long long b) {
    return a > b ? a : b;
}

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    long long x, y, w, s;
    scanf("%lld %lld %lld %lld", &x, &y, &w, &s);
    if (s > w * 2) printf("%lld", (llabs(x) + llabs(y)) * w);
    else if (s > w) {
        printf("%lld", small(llabs(x), llabs(y)) * s + (big(llabs(x), llabs(y)) - small(llabs(x), llabs(y))) * w);
    }
    else {
        if ((llabs(x) + llabs(y)) & 1) printf("%lld", (big(llabs(x), llabs(y)) - 1) * s + w);
        else printf("%lld", big(llabs(x), llabs(y)) * s);
    }
    return 0;
}