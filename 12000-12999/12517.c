#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : 20�� ���� ������ ���ڿ��� �־��� ��, �� ���ڿ��� ������ ���ڰ� �������� y���� �� �� �������� ���Ѵ�.

�ذ� ��� : ������ ���ڸ� �ҹ��ڷ� �ٲ� ����, y, ������ ���� �����غ��� ���� ���� �ִ��� Ȯ���غ��� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : GCJ 2011E A1��
*/

char s[256];

int main(void) {
    int t, l;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", s);
        printf("Case #%d: %s is ruled by ", tt, s);
        l = strlen(s) - 1;
        s[l] = tolower(s[l]);
        if (s[l] == 'y') printf("nobody.\n");
        else if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') printf("a queen.\n");
        else printf("a king.\n");
    }
    return 0;
}