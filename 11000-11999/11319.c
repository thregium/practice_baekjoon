#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : ���� 1000 ������ ���ڿ��� �־��� ��, �� ���ĺ��� ������ ������ ������ ���Ѵ�.

�ذ� ��� : ���ڿ��� ��� ���ڸ� Ȯ���ϸ� ���ĺ��� ���� ã�´�. ���ĺ��̶�� �̰��� �������� Ȯ���ϰ� �ƴ϶�� ������ ���̴�.
���� Ȯ���� ������ ������ ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : CCPC 2015 D2B��
*/

char sen[1024];

int isvowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    else return 0;
}

int main(void) {
    int s, c, v;
    scanf("%d\n", &s);
    for (int i = 0; i < s; i++) {
        fgets(sen, 1013, stdin);
        c = 0, v = 0;
        for (int j = 0; sen[j]; j++) {
            if (isalpha(sen[j])) {
                if (isvowel(tolower(sen[j]))) v++;
                else c++;
            }
        }
        printf("%d %d\n", c, v);
    }
    return 0;
}