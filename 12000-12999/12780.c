#include <stdio.h>
#include <string.h>

/*
문제 : 길이 10만 이하의 문자열에서 길이 10 이하의 문자열 N이 몇 번 포함되는지 구한다.

해결 방법 : strstr함수를 이용한다.

주요 알고리즘 : 문자열

출처 : 인하대 2016 C번
*/

char h[103000], n[16];

int main(void) {
    int r = 0;
    char* t = h - 1;
    scanf("%s%s", h, n);
    while (1) {
        t = strstr(t + 1, n);
        if (t == NULL) break;
        r++;
    }
    printf("%d", r);
    return 0;
}