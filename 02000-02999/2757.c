#include <stdio.h>
#include <string.h>

/*
���� : ������ ��� ���� ��(<= 5 * 10^8)�� �־��� ��, �̸� �������� ���̴� ��ǥ�� �ٲ� ����Ѵ�.

�ذ� ��� : ��� ���� �Է¹��� ��, ���� ���ĺ����� �ٲٰ� ��� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : GNY 2004 B��
*/

char s[1024];

void swap(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int t, r, c;
    long long x;
    while (1) {
        scanf(" R%dC%d", &r, &c);
        c--;
        if (r == 0) break;
        x = 1;
        for (int i = 0; c >= 0; i++) {
            s[i] = (c / x) % 26 + 'A';
            x *= 26;
            c -= x;
            s[i + 1] = '\0';
        }
        for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
            swap(&s[i], &s[j]);
        }
        printf("%s%d\n", s, r);
    }
    return 0;
}