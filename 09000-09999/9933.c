#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 100)���� ���̰� 14 ������ Ȧ���� ���ڿ� ��� ������ ���ڿ��� ��Ͽ� �ִ� ���ڿ��� ã��, �ش��ϴ� ���ڿ��� ���̿� ��� ���ڸ� ���Ѵ�.

�ذ� ��� : ��� ���ڿ��� ���� �ڽ��� ������ ���ڿ��� ��Ͽ� �ִ��� Ȯ���Ѵ�. �ִٸ� �ش��ϴ� ���ڿ��� �����صΰ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����, ����

��ó : COCI 13/14#5 1��
*/

char s[128][16], rev[16];

int main(void) {
    int n, len, r = 1;
    char c = '\0';
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        len = strlen(s[i]);
        for (int j = 0, k = len - 1; j < len; j++, k--) {
            rev[j] = s[i][k];
        }
        rev[len] = '\0';
        for (int j = 0; j < n; j++) {
            if (strcmp(rev, s[j])) continue;
            c = rev[len >> 1];
            r = len;
        }
    }
    if (r < 2) return 1;
    printf("%d %c", r, c);
    return 0;
}