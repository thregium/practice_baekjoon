#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : 20�� ������ �ܾ 50�� ���Ϸ� �ִ� ������ �־��� ��, �� ������ ù �ڰ� ��� ������ ���Ѵ�.
��ҹ��ڴ� �������� �ʴ´�. �ܾ�� ���ĺ����� �̷���� �ְ�, �ܾ�� �������� ���еȴ�.

�ذ� ��� : strtok���� �� �ܾ �Է¹����� �ش� �ܾ��� ù ���ڰ� ù ���ڿ� ������ �Ź� Ȯ���ϸ� �ȴ�.
��, �� ���ڵ鿡�� tolower�� ��ҹ��ڰ� ������ �ؾ� �Ѵ�. �� ���̶� �ٸ� ���ڰ� �ִٸ� �ٸ� ���̰�, ���ٸ� ���� ���̴�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ����

��ó : Latin 2010 F��
*/

char buff[2048];

int main(void) {
    int ok;
    char st, *t;
    while (1) {
        fgets(buff, 2000, stdin);
        if (buff[0] == '*') break;
        st = tolower(buff[0]);
        ok = 1;
        t = strtok(buff, " ");
        while (t != NULL) {
            t = strtok(NULL, " ");
            if (t == NULL) break;
            if (tolower(t[0]) != st) ok = 0;
        }
        printf("%c\n", ok ? 'Y' : 'N');
    }
    return 0;
}