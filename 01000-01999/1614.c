#include <stdio.h>

/*
���� : 5���� �հ������� �����ư��� ���� �� ��, N��° �հ����� M�� ���Ϸ� ����Ͽ� �� �� �ִ�
���� ū ���� ���Ѵ�.

�ذ� ��� : N�� ���� M�� Ȧ¦���� ���� ��츦 ������ �ذ��Ѵ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : SRM 390D2 1��
*/

int main(void) {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    if (n == 1) printf("%lld", m * 8);
    else if (n == 2) {
        if (m & 1) printf("%lld", m / 2 * 8 + 7);
        else printf("%lld", m / 2 * 8 + 1);
    }
    else if (n == 3) {
        if (m & 1) printf("%lld", m / 2 * 8 + 6);
        else printf("%lld", m / 2 * 8 + 2);
    }
    else if (n == 4) {
        if (m & 1) printf("%lld", m / 2 * 8 + 5);
        else printf("%lld", m / 2 * 8 + 3);
    }
    else if (n == 5) printf("%lld", m * 8 + 4);
    return 0;
}