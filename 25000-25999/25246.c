#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : 50�� ������ ���ĺ� ���ڿ��� �־��� ��, �� ���ڿ��� ������ ���� �ڿ� �ִ� ���ڵ��� �����
"ntry" ���ڿ��� �߰��� ���ڿ��� ����Ѵ�. ���ڿ��� ������ ��� �ϳ� �̻� �ִ�.

�ذ� ��� : ���ڿ��� �ڿ������� Ȯ���ϸ� ������ ��� �� ���ڸ� ����� ������ ��� Ž���� �����Ѵ�.
�׸��� �� ���ڿ��� "ntry"�� �ٿ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : GCPC 2021 B��
*/

char s[64];

int isvowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    else return 0;
}

int main(void) {
    scanf("%s", s);
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (!isvowel(tolower(s[i]))) s[i] = '\0';
        else break;
    }
    printf("%sntry", s);
    return 0;
}