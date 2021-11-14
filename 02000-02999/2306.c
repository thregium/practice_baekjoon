#include <stdio.h>
#include <string.h>

/*
���� : ���� 500 ������ DNA ���ڿ��� �־��� ��, �κ� �迭���� a-t, g-c�� ���� ��ȣ ���ڿ��� �ִ� ������ ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� �̿��Ѵ�. ������ ���������� ž�ٿ� ������� �ϸ� �ȴ�.

�ֿ� �˰��� : DP

��ó : ���� 2005 ��2��
*/

char s[512];
int mem[512][512];

int big(int a, int b) {
    return a > b ? a : b;
}

int dp(int st, int ed) {
    if (st >= ed) return 0;
    if (mem[st][ed] >= 0) return mem[st][ed];

    int r = 0;
    if ((s[st] == 'a' && s[ed] == 't') || (s[st] == 'g' && s[ed] == 'c')) r = dp(st + 1, ed - 1) + 2;
    for (int i = st; i < ed; i++) {
        r = big(r, dp(st, i) + dp(i + 1, ed));
    }
    return mem[st][ed] = r;
}

int main(void) {
    int l;
    scanf("%s", s);
    l = strlen(s);
    memset(mem, -1, sizeof(int) * 262144);
    printf("%d", dp(0, l - 1));
    return 0;
}