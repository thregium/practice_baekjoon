#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : �޸��� ���е� 10^6 ������ ���� �ƴ� �������� ���� �ٿ� ���� �־��� ��,
�� ���ڿ����� ��ģ ���ڿ����� �ִ� �������� ���� ���� ���� ���Ѵ�.

�ذ� ��� : EOF�� ���� �� ���� ���ڿ����� �Է¹����� strcat() �Լ��� �̿��� ���ڿ����� ���� ������.
���ڿ��� �������� strtoll() �Լ��� ���� �� �������� �Ľ��ϰ� ���ڿ��� ���� ���� �� ���� �̸� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�
*/

char s[10240], buff[10240];

int main(void) {
    long long r = 0, x;
    char* c = s;
    while (scanf("%s", buff) != EOF) {
        strcat(s, buff);
    }
    while (1) {
        x = strtoll(c, &c, 10);
        r += x;
        if (*c == '\0') break;
        c++;
    }
    printf("%lld", r);
    return 0;
}