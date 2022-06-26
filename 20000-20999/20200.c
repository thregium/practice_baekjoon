#include <stdio.h>

/*
���� : N(N <= 100)ȸ�� ���� ��ȭ�� �־��� ��, �� ��ȭ�� �̿��Ͽ� �׷����� �׸���.

�ذ� ��� : �� ������ ��ġ�� ��� �׷����� �׷�������. �� �� �׷����� �ִ� ������ ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : COCI 20/21#2 1��
*/

char s[128], res[256][128];

int main(void) {
    int n, now = 128, isprinting;
    scanf("%d", &n);
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < n; j++) res[i][j] = '.';
    }
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            res[now][i] = '/';
            now--;
        }
        else if (s[i] == '-') {
            now++;
            res[now][i] = '\\';
        }
        else res[now][i] = '_';
    }
    for (int i = 0; i < 256; i++) {
        isprinting = 0;
        for (int j = 0; j < n; j++) {
            if (res[i][j] != '.') isprinting = 1;
        }
        if (isprinting) printf("%s\n", res[i]);
    }
    return 0;
}