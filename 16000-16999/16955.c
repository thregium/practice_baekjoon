#include <stdio.h>

/*
���� : 10 * 10 ũ���� �����ǿ��� 'X' ���� �ϳ� �� ���� 'X'�� �̱� �� �ִ��� ���Ѵ�.

�ذ� ��� : ��� ĭ�� ���� ���� ���鼭 �̱�� ��찡 �ִ��� ���� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����
*/

char s[16][16];

int check(void) {
    int r = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 6; j++) {
            if (s[i][j] == 'X' && s[i][j + 1] == 'X' && s[i][j + 2] == 'X' && s[i][j + 3] == 'X' && s[i][j + 4] == 'X') r = 1;
            if (s[j][i] == 'X' && s[j + 1][i] == 'X' && s[j + 2][i] == 'X' && s[j + 3][i] == 'X' && s[j + 4][i] == 'X') r = 1;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (s[i][j] == 'X' && s[i + 1][j + 1] == 'X' && s[i + 2][j + 2] == 'X' && s[i + 3][j + 3] == 'X' && s[i + 4][j + 4] == 'X') r = 1;
        }
        for (int j = 4; j < 10; j++) {
            if (s[i][j] == 'X' && s[i + 1][j - 1] == 'X' && s[i + 2][j - 2] == 'X' && s[i + 3][j - 3] == 'X' && s[i + 4][j - 4] == 'X') r = 1;
        }
    }
    return r;
}

int main(void) {
    int r = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (s[i][j] != '.') continue;
            s[i][j] = 'X';
            r |= check();
            s[i][j] = '.';
        }
    }
    printf("%d", r);
    return 0;
}