#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 N(N <= 1000)개의 길이 100 이하인 문자열 중 Simon says로 시작하는 모든 문자열의 Simon says 이후 부분을 출력한다.
공백으로 시작하거나 끝나는 문자열은 없고 Simon says로 시작하는 문자열은 이후 1개 이상의 단어가 더 있다.

해결 방법 : strstr를 통해 Simon says가 맨 앞에 나오는 경우를 찾은 후, 그 경우 10번째 문자(Simon says) 이후 문자를 출력한다.

주요 알고리즘 : 문자열

출처 : NAQ 2015 I번 / 2020 F번
*/

char s[128];

int main(void) {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(s, 120, stdin);
        if (strstr(s, "Simon says") == s) {
            printf("%s", s + 10);
        }
    }
    return 0;
}