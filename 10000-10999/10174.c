#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : �־��� ���ڿ��� �Ӹ�������� Ȯ���Ѵ�. ��ҹ��ڰ� �ٸ����� ���� ���ڷ� �����Ѵ�.

�ذ� ��� : �־��� ���ڿ��� ���� �� �հ� �� �ں��� ���ڸ� �о�� �ҹ��ڷ� �ٲ� �� ���ڰ� ������ Ȯ���Ѵ�.
���� �ٸ� ���ڰ� �ϳ��� �ִٸ� �Ӹ������ �ƴϰ� ���ٸ� �Ӹ�����̴�.

�ֿ� �˰��� : ���ڿ�

��ó : PLU 2014N 5��
*/

char s[1024];

int main(void) {
    int n, r;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(s, 1000, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        if (strlen(s) > 500) return 1;
        r = 1;
        for (int x = 0, y = strlen(s) - 1; x < y; x++, y--) {
            if (tolower(s[x]) != tolower(s[y])) r = 0;
        }
        printf("%s\n", r ? "Yes" : "No");
    }
    return 0;
}