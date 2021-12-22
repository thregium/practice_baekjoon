#include <stdio.h>

/*
���� : 2�������� N���������� N(N <= 100000)�� ��Ÿ������ ���� ǥ�õǴ� �� ��� �ڸ����� ���� ���� ū �Ͱ� �׶��� ���� ���Ѵ�.

�ذ� ��� : 2�������� N���������� �� ������ ���� N�� �ڸ����� Ȯ���ϰ� �� ���� ���Ѵ�.
�� ���� ��� ���� ū ���� ������ �ȴ�.

�ֿ� �˰����� : ����, ���Ʈ ����

��ó : ���ڴ� 2018 I��
*/

int main(void) {
    int n, s, r = -1, m = -1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        s = 0;
        for (int j = n; j; j /= i) s += j % i;
        if (s > m) {
            m = s;
            r = i;
        }
    }
    printf("%d %d", m, r);
    return 0;
}