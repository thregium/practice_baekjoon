#include <stdio.h>
#include <string.h>

/*
���� : 50�ڸ� ������ �� �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� ������� �Ǵ� ���ڿ�(�ش� ���ڿ��� �ݺ��Ͽ�
�� ���ڿ��� ��� ���� �� �ִ� ���ڿ�) ��� ���� ª�� ���� ���Ѵ�. ���ٸ� No solution�� ����Ѵ�.

�ذ� ��� : ���� 1���� ª�� ���ڿ��� ���̱��� ������� �Ǵ� �� ���ϰ�, �Ǵ� ���� ������ �� ���ڿ��� ����ϸ� �ȴ�.
��������� ���δ� �ش� ���ڿ��� �ݺ��ϴ����� �� ���ڿ��� ���� ���� ��� ���ڿ� ���� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : OC 18/19_17 F��
*/

char s[64], t[64];

int main(void) {
    int sl, tl, tmp, r = 0;
    scanf("%s%s", s, t);
    sl = strlen(s);
    tl = strlen(t);
    for (int i = 1; i <= sl; i++) {
        if (sl % i || tl % i) continue;
        tmp = 1;
        for (int j = 0; s[j + i]; j++) {
            if (s[j] != s[j + i]) {
                tmp = 0;
                break;
            }
        }
        if (!tmp) continue;
        for (int j = 0; t[j + i]; j++) {
            if (t[j] != t[j + i]) {
                tmp = 0;
                break;
            }
        }
        for (int j = 0; s[j] && t[j]; j++) {
            if (s[j] != t[j]) {
                tmp = 0;
                break;
            }
        }
        if (tmp) {
            r = i;
            break;
        }
    }
    for (int i = 0; i < r; i++) {
        printf("%c", s[i]);
    }
    if (r == 0) printf("No solution");
    return 0;
}