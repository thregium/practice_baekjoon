#include <stdio.h>

/*
���� : ���� N(N <= 100)�� ���ڿ� 2���� �־��� ��, ���� ���ڿ����� ��� C�� ������ ������ ���Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�.

�ֿ� �˰��� : ����

��ó : CCC 2018 J2��
*/

char ye[128], to[128];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    scanf("%s%s", ye, to);
    for (int i = 0; i < n; i++) {
        r += ((ye[i] == 'C') && (to[i] == 'C'));
    }
    printf("%d", r);
    return 0;
}