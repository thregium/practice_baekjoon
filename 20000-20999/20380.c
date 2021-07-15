#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : D(D <= 10)���� ����� �־����� ���ڿ��� �־�����. ���ڿ��� D���� �־��� �������(���� ����) ���� �ٲ� ����,
�ش� ������ ��ķ� �ٲ� �� �־��� ��Ŀ��� ���� ���� �ᱣ������ �����´�. �̸� �ٽ� ������� ���ڿ��� �ٲپ� ����Ѵ�.
�̶� ���ڿ��� ���ڶ�� ��쿡�� ���� ���ڸ� �������� ����ؾ� �Ѵ�.

�ذ� ��� : ���ڿ��� D���� �ɰ� ���� ���� ������Ű�� ��İ��� ���� ���� �ٽ� ���ڿ��� �ٲٴ� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, ���ڿ�

��ó : MidC 1994 4��
*/

int mat[16][16], in[16], res[16];
char s[128], enc[128];

int main(void) {
    int d;
    char x;
    while (1) {
        scanf("%d", &d);
        if (d == 0) break;
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                scanf("%d", &mat[i][j]);
            }
        }
        scanf("%c", &x);
        fgets(s, 100, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        for (int i = 0; s[i]; i += d) {
            for (int j = 0; j < d; j++) {
                if (s[i + j] == '\0') in[j] = 27;
                else if (isupper(s[i + j])) in[j] = s[i + j] - 'A' + 1;
                else if (s[i + j] == ' ') in[j] = 27;
                else if (s[i + j] == ',') in[j] = 28;
                else if (s[i + j] == '.') in[j] = 29;
                else in[j] = 0;
                res[j] = 0;
            }
            for (int x = 0; x < d; x++) {
                for (int y = 0; y < d; y++) res[x] += mat[x][y] * in[y];
            }
            for (int j = 0; j < d; j++) {
                res[j] %= 30;
                if (res[j] < 0) res[j] += 30;
            }
            for (int j = 0; j < d; j++) {
                if (res[j] == 0) enc[i + j] = '?';
                else if (res[j] <= 26) enc[i + j] = 'A' + res[j] - 1;
                else if (res[j] == 27) enc[i + j] = ' ';
                else if (res[j] == 28) enc[i + j] = ',';
                else if (res[j] == 29) enc[i + j] = '.';
            }
        }
        printf("'%s'\n", enc);
        memset(s, '\0', 128);
        memset(enc, '\0', 128);
    }
    return 0;
}