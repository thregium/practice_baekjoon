#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 200)���� 250�� ������ ���ڿ��� ������ ����� ����Ѵ�.

�ذ� ��� : strcmp�� qsort() �Լ��� �̿��Ѵ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : NZPC 2008 B��
*/

char s[256][256];

int main(void) {
    int n;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        getchar();
        for (int i = 0; i < n; i++) {
            fgets(s[i], 253, stdin);
            if (s[i][strlen(s[i]) - 1] == '\n') s[i][strlen(s[i]) - 1] = '\0';
        }
        qsort(s, n, sizeof(char) * 256, strcmp);
        printf("%d\n", tt);
        for (int i = 0; i < n; i++) {
            printf("%s\n", s[i]);
        }
    }
    return 0;
}