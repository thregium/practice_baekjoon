#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ���ڿ��� M(M <= 100000)���� ���ڿ��� �־�����.
�̶�, M���� ���ڿ� ��� N���� ���ڿ��� ���ԵǴ� ���ڿ��� ������ ���Ѵ�.
�� ���ڿ��� ���̴� 15 ���ϰ�, ���ĺ��� ���ڷ� �̷���� �ִ�.

�ذ� ��� : N���� ���ڿ����� ������ ����, M���� ���ڿ��� �Է� ���� �� ����
N���� ���ڿ����� �̺� Ž���� ���� �ִ� �� ã�� ����, �ִ� ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����, �̺� Ž��

��ó : MCO 2014 A��
*/

char s[103000][16], buff[16];

int main(void) {
    int n, m, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    qsort(s, n, sizeof(char) * 16, strcmp);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", buff);
        if (bsearch(buff, s, n, sizeof(char) * 16, strcmp)) r++;
    }
    printf("%d", r);
    return 0;
}