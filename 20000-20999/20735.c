#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : N(N <= 1000)���� ��ҹ��ڷ� �̷���� 30�� ������ ���ڿ����� �־��� ��,
��ҹ��ڸ� �����ϰ� pink �Ǵ� rose�� ���Ե� ���ڿ��� ������ ���Ѵ�.

�ذ� ��� : �־��� ���ڿ��� ��� ���ڿ� tolower()�� �� ����, strstr �Լ��� ���� pink �Ǵ� rose�� �ִ�
���ڿ��� ������ ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�

��ó : SwCC 2021L A��
*/

char s[32];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; s[j]; j++) s[j] = tolower(s[j]);
        if (strstr(s, "pink") || strstr(s, "rose")) r++;
    }
    if (r) printf("%d", r);
    else printf("I must watch Star Wars with my daughter");
    return 0;
}