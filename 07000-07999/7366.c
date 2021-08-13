#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 M(M <= 10)개의 단어 가운데 "sheep"이 몇 개인지 구한다. 대소문자를 구별한다.

해결 방법 : 단어들을 입력받은 후 strcmp를 통해 sheep과 같은지 매번 확인해보며 같은 것의 수를 세면 된다.

주요 알고리즘 : 문자열

출처 : ECNA PB번
*/

char s[16];

int main(void) {
    int n, m, r;
    scanf("%d", &n);
    for (int tt = 1; tt <= n; tt++) {
        scanf("%d", &m);
        r = 0;
        for (int i = 0; i < m; i++) {
            scanf("%s", s);
            if (!strcmp(s, "sheep")) r++;
        }
        printf("Case %d: This list contains %d sheep.\n", tt, r);
    }
    return 0;
}