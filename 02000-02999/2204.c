#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
���� : �־��� N(N <= 1000)���� 20�� ������ ���ڿ����� ��ҹ��� ���� ���� ���¿��� ���������� ���� ���� ���ڿ��� ã�´�.

�ذ� ��� : �� ���ڿ��� ���� �ҹ��ڷ� ���� �Ͱ� ���� ���ڿ��� ������ ���� ��, �ҹ��� ���ڿ��� �������� �����Ѵ�.
�� ���� ó�� ���� ���� ���ڿ��� ã���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : NZPC 2005 A��
*/

char s[1024][64];

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i] + 32);
            for (int j = 0; s[i][j + 32]; j++) {
                s[i][j] = tolower(s[i][j + 32]);
            }
        }
        qsort(s, n, sizeof(char) * 64, strcmp);
        printf("%s\n", s[0] + 32);
    }
    return 0;
}