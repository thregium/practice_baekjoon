#include <stdio.h>
#include <string.h>

/*
문제 : 80자 이하의 문자열이 주어질 때, N(N <= 10)개의 바꿀 문자열 쌍이 주어진다.
순서대로 해당하는 문자열을 모두 바꾸고 난 후 나오는 문자열을 출력한다.
단, 중간 결과 나오는 문자열은 255자를 넘지 않고, 바꿀 문자열 쌍도 80자 이하로 주어진다.

해결 방법 : 문자열을 바꾸는 과정을 직접 구현하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : MidC 1999 E번
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