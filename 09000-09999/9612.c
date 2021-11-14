#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ���ڿ�(�ҹ���, 20��) ��� ���� ���� ���� �� �� ���� ���� ������ ���� �Ͱ�
�� ���� Ƚ���� ���Ѵ�.

�ذ� ��� : ���ڿ��� ���������� ������ ����, ������ ���� ���� Ƚ���� ���� ���� Ƚ���� ã�´�.
������ ��� ���߿� ���� ���� �켱�̴�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : Phuket 2013 PD��
*/

char s[1024][32], best[32];

int main(void) {
    int n, r = 1, x = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    qsort(s, n, sizeof(char) * 32, strcmp);
    strcpy(best, s[0]);
    for (int i = 1; i < n; i++) {
        if (strcmp(s[i], s[i - 1])) x = 1;
        else {
            x++;
            if (x >= r) {
                r = x;
                strcpy(best, s[i]);
            }
        }
    }
    printf("%s %d", best, r);
    return 0;
}
