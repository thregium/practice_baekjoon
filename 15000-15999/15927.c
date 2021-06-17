#include <stdio.h>
#include <string.h>

/*
문제 : 500000자리 이하의 문자열이 주어질 때, 이 문자열의 부분 문자열 가운데 가장 긴 회문이 아닌 문자열의 길이를 구한다.

해결 방법 : 주어진 문자열이 회문이 아니라면 주어진 문자열의 길이를 그대로 출력하면 된다.
만약 회문인 경우에는 모든 글자가 같은 경우 어떤 부분 문자열도 회문이 아니게 된다. 그러나 그 외에는 양 끝의 글자 가운데 하나를 지우면
둘 중 하나는 회문이 되므로 주어진 문자열의 길이에서 1을 빼서 출력하면 맞는 답이 나온다.

주요 알고리즘 : 문자열, 애드 혹

출처 : 선린 2회 L번
*/

char s[524288];
int len;

int ispal(void) {
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}

int uniform(void) {
    for (int i = 0; i < len; i++) {
        if (s[i] != s[0]) return 0;
    }
    return 1;
}

int main(void) {
    scanf("%s", s);
    len = strlen(s);
    if (ispal()) {
        if (uniform()) printf("-1");
        else printf("%d", len - 1);
    }
    else printf("%d", len);
    return 0;
}