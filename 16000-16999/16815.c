#include <stdio.h>

/*
문제 : 100자 이하의 괄호 문자열에 '*'이 추가된 문자열이 주어진다. '*'을 둘러싼 괄호가 몇 개인지 구한다.

해결 방법 : '*'의 왼쪽에 있는 여는 괄호의 수에서 닫는 괄호의 수를 빼면 답이 된다.

주요 알고리즘 : 애드 혹?

출처 : JAG 2017S3 A번
*/

char s[128];

int main(void) {
    int cnt = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '*') printf("%d", cnt);
        else if (s[i] == '(') cnt++;
        else cnt--;
    }
    return 0;
}