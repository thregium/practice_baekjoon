#include <stdio.h>
#include <string.h>

/*
���� : 1000�� ������ �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� "driip"���� ������ �� ���Ѵ�.

�ذ� ��� : strlen�� strcmp �Լ��� �̿��Ѵ�.

�ֿ� �˰��� : ���ڿ�

��ó : ��ϴ� 2021 A��
*/

char s[1024];

int main(void) {
    int len;
    scanf("%s", s + 10);
    len = strlen(s + 10);
    if (strcmp(s + 10 + len - 5, "driip")) printf("not cute");
    else printf("cute");
    return 0;
}