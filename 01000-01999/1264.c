#include <stdio.h>

/*
���� : �־��� ���ڿ����� ������ ���� ����.

�ذ� ��� : �� ���ڵ��� �������� Ȯ���� �� ������ ������ ���� ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : NZPC 2006 A��
*/

char s[512];
char* vowel = "aeiouAEIOU";

int main(void) {
    int cnt;
    while (1) {
        cnt = 0;
        fgets(s, 384, stdin);
        if (s[0] == '#') break;
        for (int i = 0; s[i]; i++) {
            for (int j = 0; vowel[j]; j++) {
                if (s[i] == vowel[j]) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}