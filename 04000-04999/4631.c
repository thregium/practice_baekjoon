#include <stdio.h>
#include <string.h>

/*
���� : �־��� N(N < 25)���� ���ڿ��� �յڷ� ���� ������ ���ġ�Ѵ�.

�ذ� ��� : ���ڿ��� �Է¹����� Ȧ����°�� ���ʿ�, ¦����°�� ���ʿ� ��ġ�� ����
��ġ�� ������� ����Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : MidC 2004 C��
*/

char strs[32], stre[32][32];

int main(void) {
    int n;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", strs);
            if (i & 1) strcpy(stre[n - (i >> 1) - 1], strs);
            else strcpy(stre[i >> 1], strs);
        }
        printf("SET %d\n", tt);
        for (int i = 0; i < n; i++) {
            printf("%s\n", stre[i]);
        }
    }
    return 0;
}