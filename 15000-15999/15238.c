#include <stdio.h>

/*
문제 : 문자열에서 가장 많이 등장한 문자와 등장 횟수를 찾는다.

해결 방법 : 각 문자의 등장횟수를 세고 그 중 가장 많이 등장한 것을 찾으면 된다.

주요 알고리즘 : 문자열

출처 : AIPO 2017F 1번
*/

char s[1024];
int a[26];

int main(void) {
    int n, r = 0;
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++) {
        a[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] > a[r]) r = i;
    }
    printf("%c %d", r + 'a', a[r]);
    return 0;
}
