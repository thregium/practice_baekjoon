#include <stdio.h>

/*
���� : N(N <= 1000)���� ��۰� ���� ����� �־�����. ����� �ܰ�� .���� ǥ�õǸ�,
�� ����� 50�� ������ �ҹ��ڷ� �־�����. �̶�, �� ��۰� ������ ��� ����Ѵ�.
����� �� ���ڴ� '+'�� �Ǿ�� �ϸ�, ���� �ۿ� �޸� ��۵��� '|'�� ���� ���ƾ� �Ѵ�.
����, ������ '.'���� ����(' ')���� ǥ���Ѵ�.

�ذ� ��� : �켱 ����� �� ���ڵ��� ���� '+'�� �ٲپ� �д�. �׸��� �� �ٸ��� '+' ���̰� ���� '.'�� ���
�� '.'���� '|'�� �ٲپ��ش�. ������ '.'���� �������� �ٲٸ� ���� �ȴ�.

�ֿ� �˰����� : ����, ���ڿ�, �� ������

��ó : JAG 2014D B��
*/

char s[1024][1280];

int main(void) {
    int n, e;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            for (int j = 0; j < 1279; j++) {
                if (s[i][j] == '.' && s[i][j + 1] != '.') s[i][j] = '+';
            }
        }
        for (int i = 0; i < 1280; i++) {
            for (int j = 0; j < n; j++) {
                if (s[j][i] != '+') continue;
                e = j + 1;
                while (s[e][i] == '.') e++;
                if (s[e][i] == '+') {
                    for (int k = j + 1; k < e; k++) s[k][i] = '|';
                }
                j = e - 1;
            }
            for (int j = 0; j < n; j++) {
                if (s[j][i] == '.') s[j][i] = ' ';
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%s\n", s[i]);
            for (int j = 0; j < n; j++) s[i][j] = '\0';
        }
    }
    return 0;
}