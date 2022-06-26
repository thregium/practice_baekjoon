#include <stdio.h>

/*
���� : ���� 3000 ������ ���ڿ� w�� w���� ���̰� ��� 3 * 10^6 ���� ������ ���ڿ� s�� �ִ�.
s �ȿ� w�� �Ƴ��׷� ������ �κ� ���ڿ��� ������ ����.

�ذ� ��� : ���ڿ� w�� �����ϴ� �� ���ĺ��� ������ �� ����, �����̵� �����츦 ���� S�� ���� G��
��� �κ� ���ڿ��� ���� ���ĺ��� ������ ���ڿ� w�� ������ ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �����̵� ������

��ó : IOI 2006_1 1��
*/

char w[3072], s[3145728];
int wcnt[52], scnt[52];

int toint(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';
    else return c - 'A' + 26;
}

int issame(int* a, int* b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main(void) {
    int g, l, res = 0;
    scanf("%d %d", &g, &l);
    scanf("%s%s", w, s);
    for (int i = 0; i < g; i++) {
        wcnt[toint(w[i])]++;
        scnt[toint(s[i])]++;
    }
    res += issame(wcnt, scnt, 52);
    for (int i = g; i < l; i++) {
        scnt[toint(s[i])]++;
        scnt[toint(s[i - g])]--;
        res += issame(wcnt, scnt, 52);
    }
    printf("%d", res);
    return 0;
}