#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
문제 : 문자열 안에서 숫자로 이루어진 부분 문자열들을 수로 변환한 것의 합을 구한다. 숫자로 이루어진 부분 문자열은
최대 6자로 이루어져 있다.

해결 방법 : 문자열을 확인하며 숫자가 나오면 임시 문자열에 그 문자를 추가한다. 숫자가 아닌 것이 나오면
임시 문자열의 값을 strtoll 함수를 이용해 수로 변환한 후 문자열을 초기화한다.
이를 문자열 전체에 대해 반복하면 된다.

주요 알고리즘 : 문자열, 파싱

출처 : JPOI 2010 13번
*/

char s[5242880], tmp[16];

int main(void) {
    int n, p = 0;
    long long r = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) tmp[p++] = s[i];
        else {
            r += strtoll(tmp, NULL, 10);
            p = 0;
            for (int j = 0; j < 16; j++) tmp[j] = '\0';
        }
    }
    r += strtoll(tmp, NULL, 10);
    printf("%lld", r);
    return 0;
}