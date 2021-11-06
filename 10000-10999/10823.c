#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : 콤마로 구분된 10^6 이하의 음이 아닌 정수들이 여러 줄에 결쳐 주어질 때,
이 문자열들을 합친 문자열에서 있는 정수들을 전부 더한 값을 구한다.

해결 방법 : EOF가 나올 때 까지 문자열들을 입력받으며 strcat() 함수를 이용해 문자열들을 합쳐 나간다.
문자열을 합쳤으면 strtoll() 함수를 통해 각 정수들을 파싱하고 문자열의 끝이 나올 때 까지 이를 반복하면 된다.

주요 알고리즘 : 문자열, 파싱
*/

char s[10240], buff[10240];

int main(void) {
    long long r = 0, x;
    char* c = s;
    while (scanf("%s", buff) != EOF) {
        strcat(s, buff);
    }
    while (1) {
        x = strtoll(c, &c, 10);
        r += x;
        if (*c == '\0') break;
        c++;
    }
    printf("%lld", r);
    return 0;
}