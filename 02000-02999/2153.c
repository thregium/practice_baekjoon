#include <stdio.h>
#include <ctype.h>

/*
문제 : 20자리 이하의 알파벳 소문자와 대문자로 이루어진 문자열이 주어질 때, 이 문자열에서 소문자를 1 ~ 26,
대문자를 27 ~ 52로 계산해 더한 수가 소수인지 구한다.

해결 방법 : 문자열을 확인하며 소문자인 경우 'a'를 빼고 1을 더한 수를 결괏값에 더하고, 대문자인 경우
'A'를 빼고 27을 더한 수를 결괏값에 더한다. 그 다음, 2부터 결괏값 - 2를 결괏값에서 나누어 보며
나누어 떨어지는 경우가 있으면 소수가 아니고, 없으면 소수로 판정하면 된다.

주요 알고리즘 : 문자열, 수학
*/

char s[32];

int main(void) {
    int r = 0, r2 = 1;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (islower(s[i])) r += s[i] - 'a' + 1;
        else if (isupper(s[i])) r += s[i] - 'A' + 27;
        else return 1;
    }
    for (int i = 2; i < r; i++) {
        if (r % i == 0) r2 = 0;
    }
    printf("It is %s prime word.", r2 ? "a" : "not a" );
    return 0;
}