#include <stdio.h>
#include <ctype.h>

/*
���� : 250�� ������ ���ڿ��� �־��� ��, �� ���ĺ��� ���� Ƚ���� ���Ѵ�. ��ҹ��ڴ� �������� �ʴ´�.

�ذ� ��� : ���ĺ��� ������ ���ĺ��� �ҹ��ڷ� �ٲپ� ������ ���� Ƚ���� ���Ѵ�. �� ����, ���� Ƚ���� ���Ŀ� �°� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : NZPC 2017 G��
*/

char s[256];
int cnt[26];

int main(void) {
    fgets(s, 253, stdin);
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) {
            cnt[tolower(s[i]) - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%c | ", 'A' + i);
        for (int j = 0; j < cnt[i]; j++) printf("*");
        printf("\n");
    }
    return 0;
}