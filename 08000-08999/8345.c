#include <stdio.h>
#include <string.h>

/*
���� : 50���� ������ ���ڿ��� �־��� ��, �� ���ڸ��� Ű���忡���� ��ġ�� ���� ����Ѵ�.

�ذ� ��� : �� ��ġ�� ���ڸ� ������ ����, �� ���ڸ� ��ġ�� �´� ���ڷ� �ٲ� �� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : PA 2008 0-1��
*/

char s[524288];
char* key[5] = { "`1234567890-=~!@#$%^&*()_+", "qwertyuiop[]\\QWERTYUIOP{}|", "asdfghjkl;'ASDFGHJKL:\"",
"zxcvbnm,./ZXCVBNM<>?", " " };
int trans[128];

int main(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; key[i][j]; j++) trans[key[i][j]] = i + 1;
    }
    fgets(s, 512000, stdin);
    if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
    for (int i = 0; s[i]; i++) {
        s[i] = trans[s[i]] + '0';
    }
    printf("%s", s);
    return 0;
}