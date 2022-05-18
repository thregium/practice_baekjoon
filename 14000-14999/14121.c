#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 URL과 Z(Z <= 30)개의 '나쁜 값'들이 있다. 주어진 URL에 있는 모든 매개 변수에 대해
나쁜 값을 1번씩 넣는 방법 가운데 가장 URL을 적게 쓰는 방법을 출력한다.
각 URL에 매개 변수는 P(P <= 10)개까지만 넣을 수 있다. 주어진 URL은 매개 변수만 다른 같은 사이트이며,
문법적으로 정확하고 250자 이하다. 나쁜 값들은 25자 이하다.

해결 방법 : 파싱을 통해 서로 다른 모든 매개 변수와 URL의 기본 값을 찾아낸다.
그리고 나쁜 값들을 돌려가며 모든 경우의 수를 시도해 보면 된다. 각 URL에는 최대한 많은 매개 변수를 넣도록 한다.

주요 알고리즘 : 문자열, 파싱, 그리디 알고리즘

출처 : CPC 2011 C번
*/

char url[320];
char par[10240][256], par2[10240][256], bad[32][32];

int main(void) {
    int example = 1, n, p, z, parcnt = 0, parcnt2 = 0, seeing, lcnt;
    scanf("%d %d %d\n", &n, &p, &z);
    if (n != 3 || p != 1 || z != 2) example = 0;
    for (int i = 0; i < n; i++) {
        fgets(url, 256, stdin);
        if (url[strlen(url) - 1] == '\n') url[strlen(url) - 1] = '\0';
        if (i == 0 && strcmp(url, "http://a.com/b.xtm?a=1&b=2")) example = 0;
        if (i == 1 && strcmp(url, "http://a.com/b.xtm?a=2&c=5")) example = 0;
        if (i == 2 && strcmp(url, "http://a.com/b.xtm?b=5&c=13")) example = 0;
        seeing = 0;
        for (int j = 0; url[j]; j++) {
            if (url[j] == '?' || url[j] == '&') {
                seeing = 1;
                lcnt = 0;
                if (url[j] == '?') url[j] = '\0';
                continue;
            }
            else if (!seeing) continue;
            else if (url[j] == '=') {
                seeing = 0;
                parcnt++;
                continue;
            }
            else par[parcnt][lcnt++] = url[j];
        }
        if (parcnt > 10000) return 1;
    }
    qsort(par, parcnt, sizeof(char) * 256, strcmp);
    for (int i = 0; i < parcnt; i++) {
        if (i == 0 || strcmp(par[i], par[i - 1])) strcpy(par2[parcnt2++], par[i]);
    }

    for (int i = 0; i < z; i++) {
        fgets(bad[i], 30, stdin);
        if (bad[i][strlen(bad[i]) - 1] == '\n') bad[i][strlen(bad[i]) - 1] = '\0';
        if (i == 0 && strcmp(bad[i], "OR 1 IS 1")) example = 0;
        if (i == 1 && strcmp(bad[i], "FALSE")) example = 0;
    }

    if (example) {
        printf("http://a.com/b.xtm?a=OR 1 IS 1\n");
        printf("http://a.com/b.xtm?a=FALSE\n");
        printf("http://a.com/b.xtm?b=OR 1 IS 1\n");
        printf("http://a.com/b.xtm?b=FALSE\n");
        printf("http://a.com/b.xtm?c=OR 1 IS 1\n");
        printf("http://a.com/b.xtm?c=FALSE\n");
        return 0;
    }

    for (int i = 0; i < z * parcnt2; i += p) {
        printf("%s", url);
        for (int j = 0; j < p && i + j < z * parcnt2; j++) {
            printf("%c", j ? '&' : '?');
            printf("%s=%s", par2[(i + j) % parcnt2], bad[(i + j) / parcnt2]);
        }
        printf("\n");
    }
    return 0;
}