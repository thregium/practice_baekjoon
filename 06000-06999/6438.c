#include <stdio.h>
#include <string.h>

/*
���� : �־��� 70�� ������ ���ڿ��� ������ ����� ����Ѵ�.

�ذ� ��� : ���ڿ��� ���̸� Ȯ���� �� �ڿ������� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : SWERC 1996 PC��
*/

char s[128];

int main(void) {
    int t, len = 1;
    scanf("%d\n", &t);
    for (int tt = 0; tt < t; tt++) {
        fgets(s, 100, stdin);
        len = strlen(s);
        if (s[len - 1] == '\n') {
            //������ ���ڰ� ������ ��� ������ �����Ѵ�.
            s[len - 1] = '\0';
            len--;
        }
        for (int i = 0, j = len - 1; i < len; i++, j--) {
            printf("%c", s[j]);
        }
        printf("\n");
    }
    return 0;
}