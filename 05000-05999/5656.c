#include <stdio.h>
#include <string.h>

/*
���� : �� ���� A�� B�� ������� �־��� ��, �� ������� ������ ���Ѵ�.

�ذ� ��� : � ��������� Ȯ���� ���� ������ ã�ƺ��� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : Phuket 2009 E��
*/

char s[4];

int main(void) {
    int a, b, r = 0;
    for (int i = 1;; i++) {
        scanf("%d %s %d", &a, s, &b);
        if (!strcmp(s, ">")) r = (a > b);
        else if (!strcmp(s, ">=")) r = (a >= b);
        else if (!strcmp(s, "<")) r = (a < b);
        else if (!strcmp(s, "<=")) r = (a <= b);
        else if (!strcmp(s, "==")) r = (a == b);
        else if (!strcmp(s, "!=")) r = (a != b);
        else break;
        printf("Case %d: ", i);
        printf("%s\n", r ? "true" : "false");
    }
    return 0;
}