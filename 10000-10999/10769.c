#include <stdio.h>

/*
문제 : 255자 이하의 문자열에서 ":-)"와 ":-(" 중 어느 것이 더 많은지 구한다.

해결 방법 : 문자열을 끝까지 확인하며 각 부분 문자열의 개수를 세 나간 다음 개수를 비교하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : CCC 2015 J2번
*/

char buff[320];

int main(void) {
    int h = 0, s = 0;
    fgets(buff, 300, stdin);
    for (int i = 0; buff[i]; i++) {
        if (buff[i] == ':' && buff[i + 1] == '-') {
            if (buff[i + 2] == ')') h++;
            else if (buff[i + 2] == '(') s++;
        }
    }
    if (h == 0 && s == 0) printf("none");
    else if (h > s) printf("happy");
    else if (h == s) printf("unsure");
    else printf("sad");
    return 0;
}