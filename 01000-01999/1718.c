#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : ���� ���ڿ�(�ҹ��� + ����, 30000�� ����)�� ��ȣȭ Ű(�ҹ���)�� �־��� ��,
������ �־��� ��Ĵ�� ��ȣȭ�� ���ڿ��� ����Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�. ������ ������ ������ ����ϸ� ���� ����������.

�ֿ� �˰��� : ���ڿ�, ����
*/

char s[32768], s2[32768];

int main(void) {
    int l2;
    fgets(s, 32000, stdin);
    if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = 0;
    fgets(s2, 32000, stdin);
    if (s2[strlen(s2) - 1] == '\n') s2[strlen(s2) - 1] = 0;
    l2 = strlen(s2);
    for (int i = 0; i < l2; i++) {
        if (!islower(s2[i])) return 1;
    }
    for (int i = 0; s[i]; i++) {
        if (islower(s[i])) {
            printf("%c", (s[i] - 'a' + (25 - (s2[i % l2] - 'a'))) % 26 + 'a');
        }
        else if (s[i] == ' ') printf(" ");
        else return 1;
    }
    return 0;
}