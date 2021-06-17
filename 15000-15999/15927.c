#include <stdio.h>
#include <string.h>

/*
���� : 500000�ڸ� ������ ���ڿ��� �־��� ��, �� ���ڿ��� �κ� ���ڿ� ��� ���� �� ȸ���� �ƴ� ���ڿ��� ���̸� ���Ѵ�.

�ذ� ��� : �־��� ���ڿ��� ȸ���� �ƴ϶�� �־��� ���ڿ��� ���̸� �״�� ����ϸ� �ȴ�.
���� ȸ���� ��쿡�� ��� ���ڰ� ���� ��� � �κ� ���ڿ��� ȸ���� �ƴϰ� �ȴ�. �׷��� �� �ܿ��� �� ���� ���� ��� �ϳ��� �����
�� �� �ϳ��� ȸ���� �ǹǷ� �־��� ���ڿ��� ���̿��� 1�� ���� ����ϸ� �´� ���� ���´�.

�ֿ� �˰��� : ���ڿ�, �ֵ� Ȥ

��ó : ���� 2ȸ L��
*/

char s[524288];
int len;

int ispal(void) {
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}

int uniform(void) {
    for (int i = 0; i < len; i++) {
        if (s[i] != s[0]) return 0;
    }
    return 1;
}

int main(void) {
    scanf("%s", s);
    len = strlen(s);
    if (ispal()) {
        if (uniform()) printf("-1");
        else printf("%d", len - 1);
    }
    else printf("%d", len);
    return 0;
}