#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 50)���� ���׸��� �־��� ��, ��� ������ ���� �ڵ尡 ��ġ�� �ʱ� ���ؼ��� �տ�������
�ּ� �� ���� ���� �ڵ带 ���� �ϴ� �� ���Ѵ�. ���� �ڵ�� �� ���ڿ� ������ ���� ���ڵ��� ���´�.
������ ���� ���� �ڵ尡 ���� ���� ��쿡�� -1�� ����Ѵ�.

�ذ� ��� : �� ������ ���� �ڵ带 ó������ ������ �����ص� ����, 1���ھ� �÷����� ��� ������ �ֳ���
��ġ�� ���� ���� �� Ȯ���Ѵ�. �׷��� ��찡 �������� �׶����� �� ���� ���� ����ϸ� �ȴ�.
�׷��� ��찡 ������ �ִٸ� -1�� ����Ѵ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : JAG 2015D B��
*/

char s[64][64], code[64][64], cpy[64][64];

int isvowel(char c) {
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') return 1;
    else return 0;
}

int main(void) {
    int n, p, t;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            p = 0;
            for (int j = 0; s[i][j]; j++) {
                if (j == 0 || isvowel(s[i][j - 1])) code[i][p++] = s[i][j];
            }
        }
        t = 0;
        for (int i = 0; i < 64; i++) {
            t = 1;
            for (int j = 0; j < n; j++) {
                cpy[j][i] = code[j][i];
            }
            for (int j = 0; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (!strcmp(cpy[j], cpy[k])) t = 0;
                }
            }
            if (t) {
                printf("%d\n", i + 1);
                break;
            }
        }
        if (!t) printf("-1\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 64; j++) {
                code[i][j] = 0;
                cpy[i][j] = 0;
            }
        }
    }
    return 0;
}