#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ���� 20 ������ ���ڿ� ��� ���������� I��°�� ���� ã�´�.

�ذ� ��� : ���ڿ����� ���Ľ�Ų ��, I - 1�� ���ڿ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : ���ִ� 2018P B��
*/

char s[128][32];

int main(void) {
    int n, l;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    qsort(s, n, sizeof(char) * 32, strcmp);
    printf("%s", s[l - 1]);
    return 0;
}