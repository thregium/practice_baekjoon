#include <stdio.h>

/*
���� : 10000 ������ �� �ڿ��� N, M, T�� �־��� ��, AN + BM + C = T�� ������Ű�� ���� �ƴ� ���� A, B, C ���
C�� ���� ���� �ϰ�, C�� ���ٸ� A + B�� ���� ũ�� �ϴ� ����� A + B�� C�� ���� ���Ѵ�.

�ذ� ��� : A�� ������ ��� ��쿡 ���� B�� �ִ��� ũ�� �ϰ� C�� ���캻��.
�̶��� A�� B, C�� �̿��� C�� ���� ��, ���ٸ� A + B�� ū ���� ���ϰ�, �׶��� A + B, C�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����
*/

int main(void) {
    int n, m, t, res, rh = 0, x;
    scanf("%d %d %d", &n, &m, &t);
    res = t;
    for (int i = t / n; i >= 0; i--) {
        x = (t - i * n) / m;
        if (t - i * n - x * m < res) {
            res = t - i * n - x * m;
            rh = x + i;
        }
        else if (t - i * n - x * m == res) {
            if (x + i > rh) rh = x + i;
        }
    }
    printf("%d %d", rh, res);
    return 0;
}