#include <stdio.h>
#include <stdlib.h>

/*
���� : 24�ڸ��� ������ ���ڿ� N(N <= 1000)���� ���� ������ ���������� �ٲ� ����� ����Ѵ�.

�ذ� ��� : strtoll �Լ��� �̿��Ѵ�.

�ֿ� �˰��� : ����

��ó : IDI 2007 G��
*/

char s[32];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        printf("%lld\n", strtoll(s, NULL, 2));
    }
    return 0;
}