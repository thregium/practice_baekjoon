#include <stdio.h>
#include <string.h>

/*
문제 : 1000자 이하의 소문자로 이루어진 문자열이 주어질 때, 이 문자열이 "driip"으로 끝나는 지 구한다.

해결 방법 : strlen과 strcmp 함수를 이용한다.

주요 알고리즘 : 문자열

출처 : 경북대 2021 A번
*/

char s[1024];

int main(void) {
    int len;
    scanf("%s", s + 10);
    len = strlen(s + 10);
    if (strcmp(s + 10 + len - 5, "driip")) printf("not cute");
    else printf("cute");
    return 0;
}