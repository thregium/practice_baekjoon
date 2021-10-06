#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : ���� 100 ������ ���ڿ��� �־��� ��, �� ���ڿ��� �Ǵ� ��� ���ڿ��� ����� ����� �������� ���Ѵ�.
��� ���ڿ��� Ư���� ���ڿ��� �� �� ���� �Ǵ� �� �� ���ڸ� ���� ���� �ش� ���ڿ��� �� �� �Ǵ� �� �ڿ� ���̴� ���� �ݺ��ؼ�
���ڿ��� ����� ���̰�, ����� ������ ���� �Ǵ� ���� ��ġ�� �ٸ��ٸ� �ٸ� ����̴�.

�ذ� ��� : �ش� ���ڿ��� ���̰� Ȧ����� ���� �ܰ��� ��� ���ڿ��� �� �� �ִ� 4���� ��찡 ���´�.
�̴� ���ڿ��� �������� ���̸� �˸� ��ġ�� �κ��� Ȯ���Ͽ� ��� ���ڿ��� �� �� �ִ� ������� Ȯ���ϰ� ��������� Ǯ�� �ȴ�.
���� ���� Ȯ���ϴ��� ���� �ٸ� ��찡 �� �� ������ �����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, ���

��ó : USACO 2014F B3��
*/

char s[128];

int track(int st, int l) {
    int tmp1 = 1, tmp2 = 1, tmp3 = 1;
    int r = 1;
    if (~l & 1) return r;
    for (int i = 0; i < (l >> 1); i++) {
        if (s[st + i] != s[st + i + (l >> 1)]) tmp1 = 0;
    }
    for (int i = 0; i < (l >> 1); i++) {
        if (s[st + i] != s[st + i + (l >> 1) + 1]) tmp2 = 0;
    }
    for (int i = 0; i < (l >> 1); i++) {
        if (s[st + i + 1] != s[st + i + (l >> 1) + 1]) tmp3 = 0;
    }
    if (tmp2 || tmp3) {
        r += track(st, (l >> 1) + 1) * (tmp2 + tmp3);
    }
    if (tmp1 || tmp2) {
        r += track(st + (l >> 1), (l >> 1) + 1) * (tmp1 + tmp2);
    }
    return r;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("scode.in", "r");
        fo = fopen("scode.out", "w");
    }
    int len;
    scanf("%s", s);
    len = strlen(s);
    printf("%d", track(0, len) - 1);
    return 0;
}