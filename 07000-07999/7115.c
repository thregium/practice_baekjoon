#include <stdio.h>

/*
���� : K(K <= 30000) ���� ũ���� ���ڿ� ������ R(R <= 30000)�� ���� �׷ȴ�.
���� �׵θ��� ������ ĭ�� ������ ���Ѵ�. �������� ������ ĭ�� �������� ĭ�� �ƴϴ�.

�ذ� ��� : �� �����͸� �̿��Ͽ� ��п��� �� X��ǥ������ Y��ǥ ������ ã�� ���� ������ ������
���̸� �̿��� �� ���� ���ϰ� 4�� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, �� ������

��ó : LtOI 11_2 3��
*/

int main(void) {
    int k, r, pos = 0, last = 0, now = 0, tnow, tlast;
    long long res = 0;
    scanf("%d %d", &k, &r);
    pos = r - 1;
    while (pos % k) pos--;
    for (; pos >= 0; pos -= k) {
        last = now;
        for (;; now++) {
            if (now & 1) {
                if (((now + 1) >> 1) * ((now + 1) >> 1) + pos * pos > r * r) break;
            }
            else {
                if ((now >> 1) * (now >> 1) + pos * pos >= r * r) break;
            }
        }

        tnow = (now >> 1) / k * 2;
        tlast = (last >> 1) / k * 2;
        if ((now & 1) || (now >> 1) % k) tnow++;
        if ((last & 1) || (last >> 1) % k) tlast++;

        if (tnow & 1) res += ((tnow - tlast) >> 1) + 1;
        else res += (tnow - tlast + 1) >> 1;
    }
    printf("%lld", res * 4);
    return 0;
}