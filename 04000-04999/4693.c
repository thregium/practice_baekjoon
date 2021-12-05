#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 문자열이 주어질 때, 마크업 태그를 제거하고 출력한다.

해결 방법 : \가 나올 때 마다 다음 글자의 종류에 따라 태그를 제거하거나 마크 여부를 토글한다.
마크되지 않은 경우이며 \*이 아니거나 \와 상관 없는 글자들은 그대로 출력한다.

주요 알고리즘 : 문자열, 파싱, 구현

출처 : MidC 1995 7번
*/

char s[103000], res[103000];

int main(void) {
    int markon = 1, len, pos;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1995\\markup.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1995\\markup_t.out", "w", stdout);
    while (fgets(s, 101300, stdin)) {
        len = strlen(s);
        pos = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '\\') {
                if (s[i + 1] == '*') {
                    markon = (!markon);
                    i++;
                    continue;
                }
                if (markon == 0) {
                    res[pos++] = s[i];
                    continue;
                }
                if (s[i + 1] == '\\') {
                    res[pos++] = '\\';
                    i++;
                    continue;
                }
                else if (s[i + 1] == 'b' || s[i + 1] == 'i') {
                    i++;
                    continue;
                }
                else if (s[i + 1] == 's') {
                    i += 2;
                    while (isdigit(s[i]) || s[i] == '.') i++;
                    i--;
                }
            }
            else res[pos++] = s[i];
        }
        res[pos] = '\0';
        printf("%s", res);
    }
    return 0;
}