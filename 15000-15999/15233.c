#include <stdio.h>
#include <string.h>

/*
문제 : 두 팀의 선수들과 득점을 한 선수들의 이름이 주어질 때, 더 많이 득점한 팀을 찾는다.

해결 방법 : 선수의 수가 많지 않으므로 직접 이름을 비교해가며 찾아도 된다.

주요 알고리즘 : 문자열, 구현

출처 : AIPO 2017P 2번
*/

char sa[32][32], sb[32][32], t[32];

int main(void) {
    int a, b, g, f, ta = 0, tb = 0;
    scanf("%d %d %d", &a, &b, &g);
    for (int i = 0; i < a; i++) {
        scanf("%s", sa[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%s", sb[i]);
    }
    for (int i = 0; i < g; i++) {
        scanf("%s", t);
        f = 0;
        for (int j = 0; j < a; j++) {
            if (!f && !strcmp(t, sa[j])) f = 1;
        }
        for (int j = 0; j < b; j++) {
            if (!f && !strcmp(t, sb[j])) f = 2;
        }
        if (f == 1) ta++;
        if (f == 2) tb++;
    }
    printf("%s", ta > tb ? "A" : ta == tb ? "TIE" : "B");
    return 0;
}