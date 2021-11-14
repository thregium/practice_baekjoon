#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 100)���� ���ڿ�(3�� �̻� 30�� ����, �ҹ���)�� �־�����
������ �־��� ��Ĵ�� ��ƾ�� ���·� �ٲ� ���ڿ��� ����Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�. 'ne'�� ���� ���� �����Ѵ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : Seoul 2018 D��
*/

char s[64];

int main(void) {
    int n, l;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 64; j++) s[j] = '\0';
        scanf("%s", s);
        l = strlen(s);
        if (l <= 2) return 1;
        if (s[l - 1] == 'a' || s[l - 1] == 'o' || s[l - 1] == 'u') s[l] = 's';
        else if (s[l - 1] == 'i' || s[l - 1] == 'y') {
            s[l - 1] = 'i';
            s[l] = 'o';
            s[l + 1] = 's';
        }
        else if (s[l - 1] == 'l' || s[l - 1] == 'r' || s[l - 1] == 'v') {
            s[l] = 'e';
            s[l + 1] = 's';
        }
        else if (s[l - 1] == 't' || s[l - 1] == 'w') {
            s[l] = 'a';
            s[l + 1] = 's';
        }
        else if (s[l - 1] == 'n') {
            s[l - 1] = 'a';
            s[l] = 'n';
            s[l + 1] = 'e';
            s[l + 2] = 's';
        }
        else if (s[l - 2] == 'n' && s[l - 1] == 'e') {
            s[l - 2] = 'a';
            s[l - 1] = 'n';
            s[l] = 'e';
            s[l + 1] = 's';
        }
        else {
            s[l] = 'u';
            s[l + 1] = 's';
        }
        printf("%s\n", s);
    }
    return 0;
}