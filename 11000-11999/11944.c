#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 2016)을 N번 출력한 것의 앞 M(M <= 2016)자리를 출력한다.

해결 방법 : N을 N번 이은 문자열을 만든 다음(최대 8064글자), M번째 자리를 끊은 것을 출력하면 된다.

주요 알고리즘 : 문자열

출처 : 고려대 2016 C번
*/

char n[8], s[103000];

int main(void) {
    int m;
    scanf("%s %d", n, &m);
    for (int i = 0; i < strtoll(n, NULL, 10); i++) {
        strcat(s, n);
    }
    s[m] = '\0';
    printf("%s", s);
    return 0;
}