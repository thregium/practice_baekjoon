#include <stdio.h>
#include <string.h>

/*
���� : ���� 10000 ������ ���ڿ��� �־��� ��, �� ���ڿ��� "D2" �Ǵ� "d2"��� ���ڿ��� ���ԵǾ����� Ȯ���Ѵ�.

�ذ� ��� : strstr �Լ��� �̿��Ѵ�.

�ֿ� �˰��� : ���ڿ�

��ó : ������ 2021 A��
*/

char s[10240];

int main(void) {
    int r = 0;
    fgets(s, 10130, stdin);
    if (strstr(s, "d2")) r = 1;
    if (strstr(s, "D2")) r = 1;
    printf("%s", r ? "D2" : "unrated");
    return 0;
}