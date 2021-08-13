#include <stdio.h>

/*
문제 : 길이 L(L <= 100)인 두 문자열이 주어질 때, 두 문자열 사이 다른 문자의 개수를 구한다.

해결 방법 : 두 문자열을 확인하며 서로 다른 문자의 수를 세면 된다.

주요 알고리즘 : 구현, 문자열

출처 : UVaH 2012 A번
*/

char que[128], ans[128];

int main(void) {
    int t, l, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &l);
        scanf("%s%s", que, ans);
        r = 0;
        for (int i = 0; i < l; i++) {
            if (que[i] != ans[i]) r++;
        }
        printf("Case %d: %d\n", tt, r);
    }
    return 0;
}