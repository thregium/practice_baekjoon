#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 입력한 문자열과 비밀번호가 주어질 때, 주어진 문자열을 비밀번호로 인정하는 지 여부를 확인한다.
문자열은 다음 상황에만 인정된다.
1. 문자열과 비밀번호가 같은 경우
2. 비밀번호의 앞에 한 숫지를 더하면 문자열인 경우
3. 비밀번호의 뒤에 한 숫자를 더하면 문자열인 경우
4. 문자열의 대소문자를 바꾸면 비밀번호인 경우
문자열과 비밀번호는 모두 100자 이하의 대소문자와 숫자로 이루어져 있다.

해결 방법 : 비밀번호로 인정되는 문자열의 가짓수가 적으므로(22가지), 모든 인정되는 문자열들을 만들어 보고,
그 중 입력된 것이 있는 지 확인하면 된다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : MidC 2019 I번
*/

char s[128], p[128], s1[128], s2[128], s3[128];

int main(void) {
    int l, r = 0;
    scanf("%s%s", s, p);
    l = strlen(p);
    strcpy(s1 + 1, p);
    strcpy(s2, p);
    strcpy(s3, p);
    for (char i = '0'; i <= '9'; i++) {
        s1[0] = i;
        if (!strcmp(s, s1)) r = 1;
    }
    for (char i = '0'; i <= '9'; i++) {
        s2[l] = i;
        if (!strcmp(s, s2)) r = 1;
    }
    for (int i = 0; i < l; i++) {
        if (islower(p[i])) s3[i] = toupper(p[i]);
        else if (isupper(p[i])) s3[i] = tolower(p[i]);
    }
    if (!strcmp(s, s3)) r = 1;
    if (!strcmp(s, p)) r = 1;
    printf("%s", r ? "Yes" : "No");
    return 0;
}