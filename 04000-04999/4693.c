#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : ���ڿ��� �־��� ��, ��ũ�� �±׸� �����ϰ� ����Ѵ�.

�ذ� ��� : \�� ���� �� ���� ���� ������ ������ ���� �±׸� �����ϰų� ��ũ ���θ� ����Ѵ�.
��ũ���� ���� ����̸� \*�� �ƴϰų� \�� ��� ���� ���ڵ��� �״�� ����Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ����

��ó : MidC 1995 7��
*/

char s[103000], res[103000];

int main(void) {
    int markon = 1, len, pos;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1995\\markup.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1995\\markup_t.out", "w", stdout);
    while (fgets(s, 101300, stdin)) {
        len = strlen(s);
        pos = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '\\') {
                if (s[i + 1] == '*') {
                    markon = (!markon);
                    i++;
                    continue;
                }
                if (markon == 0) {
                    res[pos++] = s[i];
                    continue;
                }
                if (s[i + 1] == '\\') {
                    res[pos++] = '\\';
                    i++;
                    continue;
                }
                else if (s[i + 1] == 'b' || s[i + 1] == 'i') {
                    i++;
                    continue;
                }
                else if (s[i + 1] == 's') {
                    i += 2;
                    while (isdigit(s[i]) || s[i] == '.') i++;
                    i--;
                }
            }
            else res[pos++] = s[i];
        }
        res[pos] = '\0';
        printf("%s", res);
    }
    return 0;
}