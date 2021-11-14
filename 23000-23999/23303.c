#include <stdio.h>
#include <string.h>

/*
문제 : 길이 10000 이하의 문자열이 주어질 때, 이 문자열에 "D2" 또는 "d2"라는 문자열이 포함되었는지 확인한다.

해결 방법 : strstr 함수를 이용한다.

주요 알고리즘 : 문자열

출처 : 연세대 2021 A번
*/

char s[10240];

int main(void) {
    int r = 0;
    fgets(s, 10130, stdin);
    if (strstr(s, "d2")) r = 1;
    if (strstr(s, "D2")) r = 1;
    printf("%s", r ? "D2" : "unrated");
    return 0;
}