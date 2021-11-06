#include <stdio.h>
#include <ctype.h>

/*
문제 : 길이 100 이하의 문자열이 주어질 때, 이 문자열에 대소문자를 구별하지 않고 모든 알파벳이 들어있는지 확인한다.
없는 경우 없는 문자들을 소문자로 알파벳 순서대로 출력한다.

해결 방법 : 먼저 각 문자들을 확인하며 각 문자의 등장 여부를 확인한다.(대소문자에 따라 다르게 처리)
그리고 모든 문자가 들어있는지 확인한 다음 들어있지 않은 문자가 있다면 다시 이를 확인하며 알파벳 순서대로
없는 문자들을 출력하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : NAQ 2015 F번
*/

char s[128], chk[26];

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        fgets(s, 120, stdin);
        if (s[0] == '\n') {
            i--;
            continue;
        }
        for (int j = 0; j < 26; j++) chk[j] = 0;
        for (int j = 0; s[j]; j++) {
            if (isupper(s[j])) chk[s[j] - 'A'] = 1;
            else if (islower(s[j])) chk[s[j] - 'a'] = 1;
        }
        r = 1;
        for (int j = 0; j < 26; j++) {
            if (!chk[j]) r = 0;
        }
        if (r) printf("pangram\n");
        else {
            printf("missing ");
            for (int j = 0; j < 26; j++) {
                if (!chk[j]) printf("%c", j + 'a');
            }
            printf("\n");
        }
    }
    return 0;
}