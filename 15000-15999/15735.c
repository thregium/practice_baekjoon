#include <stdio.h>

/*
���� : ���� N(N <= 10000)�� �ﰢ�� ���� �ﰢ�� ������ ���Ѵ�.

�ذ� ��� : ��Ģ�� ã�Ƽ� ���� �Ʒ� �ﰢ������ ������ Ǯ�� �ȴ�.

�ֿ� �˰��� : ����

��ó : �Ѿ��E 2018 4��
*/

int main(void) {
    int n;
    long long r = 0, s = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        s += i;
        r += s;
    }
    s = 0;
    for (int i = 1; i <= n - 1; i++) s += i;
    for (int i = n - 1; i > 0; i -= 2) {
        r += s;
        s -= 2 * i - 1;
    }
    printf("%lld", r);
    return 0;
}