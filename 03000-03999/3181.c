#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : 100�� ������ �ҹ��ڿ� �������� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� ���� �ܾ �����.
���ڿ��� ���� �ܾ�� �� �ܾ��� �� �� ���ڸ� ���ͼ� ���� �빮�ڷ� ���� ���̴�. ��, 10���� �ܾ�� �����ϵ�,
�� �տ� �ִ� ���� �����Ѵ�.

�ذ� ��� : ù ���ڴ� �׻� ����ϵ��� �ϰ�, ���� ���ڴ� �� ���ڰ� �����̰� ���� ���ڰ� ���ڶ�� ������� Ȯ���Ѵ�.
���� 10���� �ܾ� ��� �ϳ���� ����ؼ��� �� �ȴ�. �� ���� ��쿡�� ����ϵ��� �Ѵ�. �ش� �ܾ�� �����ϴ�
�ٸ� �ܾ��� �Ϻ��� ���� �ش� �ܾ �ƴϴ�.

�ֿ� �˰��� : ���ڿ�

��ó : CHCI 2005RJ 1��
*/

char s[256];
const char* no[] = { "i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili" };

int main(void) {
    int t;
    fgets(s, 120, stdin);
    for (int i = 0; s[i]; i++) {
        if (i == 0) {
            if (!isalpha(s[i])) return 1;
            printf("%c", toupper(s[i]));
        }
        else if (s[i - 1] == ' ' && isalpha(s[i])) {
            t = 0;
            for (int j = 0; j < 10; j++) {
                if (strstr(&s[i], no[j]) == &s[i] && (s[i + strlen(no[j])] == ' ' || s[i + strlen(no[j])] == '\0')) t = 1;
            }
            if (t) continue;
            printf("%c", toupper(s[i]));
        }
    }
    return 0;
}