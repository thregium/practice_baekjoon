#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ���ڿ�(�ҹ���, 20�� ����)�� �־��� ��, ���� �ٸ� ���ڿ��� ������ ���Ѵ�.

�ذ� ��� : ���ڿ����� �Է¹ް� ������ ����, ù ��° ���ڿ����� ���ڿ��� ������ ����,
���� ���� ���ڿ��� ���� ���ڿ��� ���ٸ� ���� �ʴ´�. �� ��� �� ���ڿ��� ������ ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : Rocky 2015 J��
*/

char s[128][32];

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
        }
        qsort(s, n, sizeof(char) * 32, strcmp);
        r = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && !strcmp(s[i], s[i - 1])) continue;
            r++;
        }
        printf("%d\n", r);
    }
    return 0;
}