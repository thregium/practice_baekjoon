#include <stdio.h>
#include <string.h>

/*
���� : ��ȣȭ�� 15000�� ������ ���ڿ�(�빮��)�� �־��� ��, �� ���ڿ��� ������ �־��� ��Ĵ�� ��ȣȭ�Ѵ�.
���ڿ��� �ѷ� �ɰ��� ���ڿ��� ���� �������� ���ڵ��� ���� ����, ���� ��ġ�� ����̴�.

�ذ� ��� : ������ �־������ �����Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : ECNA 2017 C��
*/

char s[16384];

void rot(int st, int ed) {
    int sum = 0;
    for (int i = st; i < ed; i++) {
        sum += s[i] - 'A';
    }
    for (int i = st; i < ed; i++) {
        s[i] = ((s[i] - 'A') + sum) % 26 + 'A';
    }
}

int main(void) {
    int l;
    scanf("%s", s);
    l = strlen(s);
    if (l & 1) return 1;
    rot(0, l >> 1);
    rot(l >> 1, l);
    for (int i = 0; i < (l >> 1); i++) {
        printf("%c", ((s[i] - 'A') + (s[i + (l >> 1)] - 'A')) % 26 + 'A');
    }
    return 0;
}