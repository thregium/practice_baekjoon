#include <stdio.h>

/*
���� : 200�� ������ �ҹ��ڿ� ��ȣ�� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� ��ȣ �� ���ڵ���
������ ���ڿ��� ���Ѵ�. ��ȣ�� ������� �ʴ´�.
��ȣ�� ���̴� �ִ� 1�ܰ��̰� ��� ��ȣ�� �ùٸ��� ¦������ �ִ�.

�ذ� ��� : ���ڿ�, �Ľ�, ����

�ֿ� �˰��� : ���ڿ�, �Ľ�, ����

��ó : RCC 2011Q1 A��
*/

char s[256], tok[256];

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int p = 0, l = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            p++;
            tok[l] = '\0';
            printf("%s", tok);
            l = 0;
            continue;
        }
        else if (s[i] == ')') {
            p--;
            tok[l] = '\0';
            for (int j = 0, k = l - 1; j < k; j++, k--) swap(&tok[j], &tok[k]);
            printf("%s", tok);
            l = 0;
            continue;
        }
        if (p > 1 || p < 0) return 1;
        tok[l++] = s[i];
        if (!s[i + 1]) {
            tok[l] = '\0';
            printf("%s", tok);
        }
    }
    return 0;
}