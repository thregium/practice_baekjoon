#include <stdio.h>
#include <ctype.h>

/*
문제 : 비밀번호가 주어지면 이 비밀번호가 유효한지 검사한다.
유효한 비밀번호는 대문자, 소문자, 숫자, 특수문자가 1개 이상 포함되어야 하고, 12자 이상이어야 한다.

해결 방법 : 먼저, 비밀번호의 길이를 확인해 12자보다 적다면 유효하지 않음을 출력한다.
12자 이상인 경우, 각 글자의 타입별로 세놓은 다음 0개인 것이 있다면 유효하지 않은 것이고 전부 1개 이상인 경우 유효한 것임을 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : AIPO 2017F 2번
*/

char pw[128];

int main(void) {
    int t, n, u, l, d, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d%s", &n, pw);
        if (n < 12) {
            printf("invalid\n");
            continue;
        }
        u = 0, l = 0, d = 0, s = 0;
        for (int i = 0; i < n; i++) {
            if (isupper(pw[i])) u++;
            else if (islower(pw[i])) l++;
            else if (isdigit(pw[i])) d++;
            else s++;
        }
        if (u && l && d && s) printf("valid\n");
        else printf("invalid\n");
    }
    return 0;
}
