#include <stdio.h>
#include <string.h>

/*
문제 : 10^100 이하의 정수가 주어질 때, 이 수가 몇 자리 수인지 구한다.

해결 방법 : 수를 문자열로 입력받으면 문자열의 길이가 수의 길이가 된다.

주요 알고리즘 : 문자열

출처 : NAQ 2016 J번
*/

char s[128];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        printf("%d\n", strlen(s));
    }
    return 0;
}
