#include <stdio.h>
#include <string.h>

/*
���� : ���� 500 ������ 'm', 'e', 'w'�� �̷���� ���ڿ��� �־�����. �� ���ڿ��� �κ� ���
'm'�� 'w'�� ������ ���̿� 'e'�� ���� �� �翷���� mew ���ڿ��� ������ ���,
�Ǵ� �� ���ڿ��� ��� mew ���ڿ��̴�. �̶�, �־��� ���ڿ��� mew ���ڿ��� �� Ȯ���Ѵ�.

�ذ� ��� : ���ڿ��� �ɰ����� mew ���ڿ��� �� Ȯ���Ѵ�. �̶�, ���� ������ �ݺ��ϸ�
���� �ð��� ������Ƿ� ���� ������ ����� �޸������̼��� ���� �ð��� �����Ѵ�.

�ֿ� �˰��� : DP, ���ڿ�, ���� ����?

��ó : JAG 2011W3 A��
*/

char s[512];
int mem[512][512];

int iscat(int st, int ed) {
    if (st > ed) return mem[st][ed] = 1;
    if (s[st] != 'm' || s[ed] != 'w' || (ed - st) % 3 != 2) return mem[st][ed] = 0;
    if (mem[st][ed] >= 0) return mem[st][ed];
    int r = 0;
    for (int i = st + 1; i < ed; i++) {
        if (s[i] == 'e') {
            r |= iscat(st + 1, i - 1) & iscat(i + 1, ed - 1);
        }
    }
    return mem[st][ed] = r;
}

int main(void) {
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) mem[i][j] = -1;
    }
    scanf("%s", s);
    if (iscat(0, strlen(s) - 1)) printf("Cat\n");
    else printf("Rabbit\n");
    return 0;
}