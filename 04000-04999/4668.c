#include <stdio.h>
#include <string.h>

/*
���� : 80�� ������ ���ڿ��� �־��� ��, N(N <= 10)���� �ٲ� ���ڿ� ���� �־�����.
������� �ش��ϴ� ���ڿ��� ��� �ٲٰ� �� �� ������ ���ڿ��� ����Ѵ�.
��, �߰� ��� ������ ���ڿ��� 255�ڸ� ���� �ʰ�, �ٲ� ���ڿ� �ֵ� 80�� ���Ϸ� �־�����.

�ذ� ��� : ���ڿ��� �ٲٴ� ������ ���� �����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : MidC 1999 E��
*/

char s[16][2][128];
char str[512], nxt[512];

int main(void) {
    int n;
    char* c;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1999\\autoedit\\autoedit.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1999\\autoedit\\autoedit_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            fgets(s[i][0], 100, stdin);
            if (s[i][0][strlen(s[i][0]) - 1] == '\n') s[i][0][strlen(s[i][0]) - 1] = '\0';
            if (strlen(s[i][0]) == 0) {
                i--;
                continue;
            }
            fgets(s[i][1], 100, stdin);
            if (s[i][1][strlen(s[i][1]) - 1] == '\n') s[i][1][strlen(s[i][1]) - 1] = '\0';
        }
        fgets(str, 128, stdin);
        if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
        for (int i = 0; i < n; i++) {
            while (strstr(str, s[i][0])) {
                c = strstr(str, s[i][0]);
                for (char* ca = str, *cb = nxt; ca < c; ca++, cb++) *cb = *ca;
                strcat(nxt, s[i][1]);
                strcat(nxt, c + strlen(s[i][0]));
                strcpy(str, nxt);
                memset(nxt, 0, 512);
            }
        }
        printf("%s\n", str);
    }
    return 0;
}