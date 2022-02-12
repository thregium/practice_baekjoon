#include <stdio.h>
#define MOD 1000000007

/*
문제 : 길이 10000 이하의 소문자와 '?'로 이루어진 문자열이 주어질 때,
이 문자열에서 '?'를 이미 존재하는 다른 문자로 바꾸어 그룹 문자열이 되도록 하는 방법의 수를 구한다.
방법이 0가지인 경우는 주어지지 않는다.

해결 방법 : ?의 양 끝 문자가 서로 다른 문자인 경우 ?의 길이 + 1 만큼의 가짓수가 가능하다.
서로 같은 문자 또는 양 끝 중 하나가 끝에 접해있는 경우 그쪽과 같이 바꾸어야 하므로 1가지만 가능하다.
가능한 모든 경우를 곱하면 답이 된다.

주요 알고리즘 : 수학, 조합론, 문자열

출처 : Arab 2013 A번
*/

char s[10240];

int main(void) {
    int t, res, e;
    //freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2013\\acpc2013-IO-A\\sticker.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        res = 1;
        for (int i = 0; s[i]; i++) {
            if (s[i] != '?') continue;
            e = i;
            while (s[e] == '?') e++;
            if (s[e] == '\0') break;
            else if (i > 0 && s[i - 1] != s[e]) res = ((long long)res * (e - i + 1)) % MOD;
            i = e;
        }
        printf("%d\n", res);
    }
    return 0;
}