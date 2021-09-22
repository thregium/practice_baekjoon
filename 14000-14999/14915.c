#include <stdio.h>

/*
���� : 10���� N(N <= 10^6)�� �־��� ��, M(M <= 16)�������� ǥ���� ����� ����Ѵ�.

�ذ� ��� : ������ �ڸ������� �������� ������ ��, �ٽ� �������� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : �Ѿ��E 2017A G��
*/

int res[32];

int main(void) {
    int m, n, p = 0;
    scanf("%d %d", &m, &n);
    if (m == 0) {
        printf("0");
        return 0;
    }
    while (m) {
        res[p++] = m % n;
        m /= n;
    }
    for (int i = p - 1; i >= 0; i--) {
        if (res[i] < 10) printf("%d", res[i]);
        else printf("%c", res[i] - 10 + 'A');
    }
    return 0;
}