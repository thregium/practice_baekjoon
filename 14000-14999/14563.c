#include <stdio.h>

/*
���� : T(T < 1000)���� ������ ���� N(N < 10000)�� ���������� ���������� ���׼����� ���Ѵ�.

�ذ� ��� : 1���� N - 1������ ��� ���� ���� N�� ������� Ȯ���ϸ� N�� ������� ���� ���� ���� ������ �Ǻ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, ���Ʈ ����

��ó : �߾Ӵ� 2017 C��
*/

int main(void) {
    int t, n, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        s = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) s += i;
        }
        if (s < n) printf("Deficient\n");
        else if (s == n) printf("Perfect\n");
        else printf("Abundant\n");
    }
    return 0;
}