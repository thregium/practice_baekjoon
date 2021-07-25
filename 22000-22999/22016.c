#include <stdio.h>
#include <ctype.h>

/*
문제 : N(N <= 100)자의 문자열에서 K번째 이후의 문자의 대소문자를 반전시킨다.

해결 방법 : K번째부터 문자를 살피며 대문자라면 소문자로 바꾸고 소문자라면 대문자로 바꾼다.

주요 알고리즘 : 문자열, 구현

출처 : JOIG 2021 2번
*/

char t[128];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", t);
    for (int i = k - 1; t[i]; i++) {
        if (isupper(t[i])) t[i] = tolower(t[i]);
        else t[i] = toupper(t[i]);
    }
    printf("%s", t);
    return 0;
}