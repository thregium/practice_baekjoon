#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : 100�� ������ ���ڿ� ���ĺ����� �̷���� ���ڿ� S���� ���ڸ� �����ϸ�
100�� ������ ���ĺ����� �̷���� ���ڿ� K�� ã�� �� �ִ��� ���Ѵ�.

�ذ� ��� : isalpha() �Լ��� ����Ͽ� ���ڰ� �ƴ� ���ڸ� ���ο� ���ڿ��� �����ϰ� strstr() �Լ��� �̿��Ͽ�
���ڿ��� �ִ��� ã���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : ����/�߾� 2018 G��
*/

char s[128], s2[128], k[128];

int main(void) {
    int p = 0;
    scanf("%s%s", s, k);
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) s2[p++] = s[i];
    }
    if (strstr(s2, k)) printf("1");
    else printf("0");
    return 0;
}