#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 100)개의 문자열에 대해 주어진 패턴과 맞는지 구한다. 주어진 패턴은 (문자열)*(문자열)로 되어있고,
*에는 0개 이상의 문자가 들어갈 수 있다.

해결 방법 : 주어진 패턴을 접두사와 접미사로 분리하고, 접두사와 접미사가 맞는지 확인하고 서로 겹치지 않는지 확인하면 된다.

주요 알고리즘 : 문자열, 파싱

출처 : COCI 13/14#6 1번
*/

char patt[128], pref[128], suff[128], buff[128];

int main(void) {
    int n, pl, sl, bl;
    //freopen("E:\\PS\\Contest\\COCI\\13-14\\contest6_testdata\\vjeko\\vjeko.in.6b", "r", stdin);
    //freopen("E:\\PS\\Contest\\COCI\\13-14\\contest6_testdata\\vjeko\\vjeko_t.out.6b", "w", stdout);
    scanf("%d", &n);
    scanf("%s", patt);
    strcpy(pref, strtok(patt, "*"));
    strcpy(suff, strtok(NULL, "*"));
    pl = strlen(pref);
    sl = strlen(suff);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        bl = strlen(buff);
        if (strstr(buff, pref) == buff && bl - sl >= pl && !strcmp(&buff[bl - sl], suff)) printf("DA\n");
        else printf("NE\n");
    }
    return 0;
}