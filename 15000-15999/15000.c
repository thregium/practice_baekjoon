#include <stdio.h>
#include <ctype.h>

/*
���� : 10^6 ���� ������ �ҹ��ڷθ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� �빮�ڷ� ��ȯ�� ����� ����Ѵ�.

�ذ� ��� : toupper �Լ��� �̿��Ѵ�.

�ֿ� �˰��� : ����

��ó : BAPC 2017P X��
*/

char s[1048576];

int main(void) {
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        printf("%c", toupper(s[i]));
    }
    return 0;
}