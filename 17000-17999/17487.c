#include <stdio.h>
#include <ctype.h>

/*
���� : ���� 100 ������ ��ҹ��ڿ� �������� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� ������� �ִ���
�յ��ϰ� ���� �� �� ���� Ÿ�ڸ� ġ�� Ƚ���� ���Ѵ�. ����Ʈ�� �Ź� ������ �ϰ�, �����̽��ٿ� ����Ʈ�� �� ������ ���� �� �ִ�.
����, �޼����δ� Y, G, B������ ������ �޼հ� �������� ��� 1ȸ �� ���� ĥ �� �ִٸ� �޼��� �� ���� ģ��.

�ذ� ��� : ���ڿ����� �޼�, ������, ������� ĥ �� �ִ� ���ڵ��� ���� ����. �빮�ڿ� �����̽��ٿ� �����Ѵ�.
�� ����, �� ������ �� ���� �ʿ� �����ִ��� ������ ���� ������ �������� ��� �Է��� �����ش�.
������ �´� ��쿡�� ��ü �Է��� ������ ������ ����ϵ� Ȧ���� ��� ������ �� ���� ����Ѵ�.

�ֿ� �˰��� : ����, ����

��ó : �Ǳ��� 2019 A��
*/

char s[128];
const char* left = "qwertyasdfgzxcvb", * right = "uiophjklnm";

int main(void) {
    int l = 0, r = 0, m = 0;
    fgets(s, 120, stdin);
    for (int i = 0; s[i]; i++) {
        if (isupper(s[i])) {
            m++;
            for (int j = 0; left[j]; j++) {
                if (tolower(s[i]) == left[j]) l++;
            }
            for (int j = 0; right[j]; j++) {
                if (tolower(s[i]) == right[j]) r++;
            }
        }
        else if (islower(s[i])) {
            for (int j = 0; left[j]; j++) {
                if (s[i] == left[j]) l++;
            }
            for (int j = 0; right[j]; j++) {
                if (s[i] == right[j]) r++;
            }
        }
        else if (s[i] != ' ' && s[i] != '\n') return 1;
        else if (s[i] == ' ') m++;
    }
    if (m + l <= r) printf("%d %d", m + l, r);
    else if (m + r <= l) printf("%d %d", l, m + r);
    else printf("%d %d", (l + r + m + 1) >> 1, (l + r + m) >> 1);
    return 0;
}
