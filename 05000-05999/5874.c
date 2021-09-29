#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : ���� N(N <= 50000)�� '('�� ')'�� �̷���� ���ڿ��� �־��� ��, "((" ���Ŀ� "))"�� ���� �������� ������ ���Ѵ�.

�ذ� ��� : ���� �����ʺ��� �κ� ���ڿ� "))"�� ������ ������ ����. �� ����, ���ʺ��� �о���� �κ� ���ڿ� "(("��
���� �� ���� �����ʿ� �ִ� "))"�� ������ �ᱣ���� ���Ѵ�. ���������� �� ���� �ᱣ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ���շ�, ���� ��

��ó : USACO 2012N B1��
*/

char s[51200];
int rsum[51200];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cowfind.in", "r");
        fo = fopen("cowfind.out", "w");
    }
    int l;
    long long r = 0;
    scanf("%s", s);
    l = strlen(s);
    for (int i = l - 1; i >= 0; i--) {
        if (s[i] == ')' && s[i + 1] == ')') rsum[i] = rsum[i + 1] + 1;
        else rsum[i] = rsum[i + 1];
    }

    for (int i = 0; i < l; i++) {
        if (s[i] == '(' && s[i + 1] == '(') r += rsum[i];
    }
    printf("%lld", r);
    return 0;
}