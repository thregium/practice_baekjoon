#include <stdio.h>
#include <assert.h>

/*
문제 : 길이 L(L <= 15)의 소문자로 이루어진 단어 D(D <= 5000)개가 주어진다. N(N <= 500)개의 패턴에 대해
각 패턴에 대응하는 단어의 개수를 구한다. 각 패턴은 L개의 단위로 이루어져 있고,
각 단위는 알파벳 한 자 또는 괄호 안의 알파벳들로 이루어져 있다.

해결 방법 : 각 패턴을 입력받을 때 마다 각 단위에 포함되는 알파벳들을 찾아나간다.
이는 괄호 깊이가 0일 때 다음 단위로 이동하고, 알파벳이 있으면 현재 단위에 그 알파벳을 추가하는 방식으로
구현 가능하다. 그 다음, 각 단어마다 글자 순서대로 확인하며 모든 알파벳이 단위에 포함되는 지 확인하여
그러한 알파벳을 세고, 그 개수를 구하면 된다.

주요 알고리즘 : 문자열, 파싱, 브루트 포스

출처 : GCJ 2009Q A2번
*/

char word[5120][32], s[512];
int chk[5120], finding[16][32];

int main(void) {
    int l, d, n, par, pt, res = 0;
    scanf("%d %d %d", &l, &d, &n);
    for (int i = 0; i < d; i++) {
        scanf("%s", word[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        par = 0, pt = 0;
        for (int j = 0; j < d; j++) chk[j] = 1;
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < 26; k++) finding[j][k] = 0;
        }
        for (int j = 0; s[j]; j++) {
            if (s[j] == '(') par++;
            else if (s[j] == ')') par--;
            else finding[pt][s[j] - 'a'] = 1;
            if (par == 0) pt++;
        }
        assert(pt == l);
        
        res = 0;
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < d; k++) {
                if (!finding[j][word[k][j] - 'a']) chk[k] = 0;
            }
        }
        for (int j = 0; j < d; j++) res += chk[j];
        printf("Case #%d: %d\n", i, res);
    }
    return 0;
}