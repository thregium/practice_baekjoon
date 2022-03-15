#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 토너먼트의 대진이 문자열 형태로 주어질 때, 각 팀의 승리 횟수가 주어진 형태와 같을 수 있을 지 구한다.

해결 방법 : 재귀적으로 각 팀의 승패를 맞춰나간 다음 승리 횟수가 같은 지 확인하면 된다.
승리 팀은 남은 승리 횟수가 많은 팀으로 한다. 양쪽이 같다면 (당연히 조건을 만족할 수 없지만)
아무 팀이나 승리시키도록 한다.

주요 알고리즘 : 문자열, 파싱, 재귀, 그리디 알고리즘

출처 : JAG 2017P B번
*/

int win[26];
char s[1024];

int tour(int st, int ed) {
    int lt = -1, rt = -1, dep = 0;
    if (st == ed) return s[st] - 'a';
    if (s[st] == '[') st++;
    if (s[ed] == ']') ed--;
    for (int i = st; i <= ed; i++) {
        if (s[i] == '[') dep++;
        else if (s[i] == ']') dep--;
        else if (dep == 0 && s[i] == '-') {
            lt = tour(st, i - 1);
            rt = tour(i + 1, ed);
        }
    }

    if (win[lt] >= win[rt]) {
        win[lt]--;
        return lt;
    }
    else {
        win[rt]--;
        return rt;
    }
}

int main(void) {
    int a = 0, w, r = 1;
    char c;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (islower(s[i])) a++;
    }
    for (int i = 0; i < a; i++) {
        scanf(" %c %d", &c, &w);
        win[c - 'a'] = w;
    }

    tour(0, strlen(s) - 1);
    for (int i = 0; i < 26; i++) {
        if (win[i]) r = 0;
    }
    printf("%s\n", r ? "Yes" : "No");
    return 0;
}