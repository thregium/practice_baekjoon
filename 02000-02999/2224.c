#include <stdio.h>

/*
���� : N(N <= 10000)���� �������� ���ĺ��� �̿��� �־�����, �� �������� �̿��� ���� ������
�ڸ����� ���� �������� ���� ����Ѵ�.

�ذ� ��� : ���ǿ��� �İ����� ���� ������ ���� ���� ����, �÷��̵�-���� �˰����� �̿���
���������� ���� ������ �������� ���� ���ϰ� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����
*/

int ok[52][52];

int toint(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    else return c - 'a' + 26;
}

char tochar(int x) {
    if (x < 26) return x + 'A';
    else return x + 'a' - 26;
}

int main(void) {
    int n, r = 0;
    char c1, c2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c => %c", &c1, &c2);
        ok[toint(c1)][toint(c2)] = 1;
    }
    for (int k = 0; k < 52; k++) {
        for (int i = 0; i < 52; i++) {
            for (int j = 0; j < 52; j++) {
                ok[i][j] |= (ok[i][k] & ok[k][j]);
            }
        }
    }
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            if (i == j) continue;
            r += ok[i][j];
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            if (i == j || (!ok[i][j])) continue;
            printf("%c => %c\n", tochar(i), tochar(j));
        }
    }
    return 0;
}