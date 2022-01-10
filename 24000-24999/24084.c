#include <stdio.h>

/*
문제 : N(N <= 100)자의 'J', 'O', 'I'로 이루어진 문자열이 주어질 때, 다음 글자가 'J'인 문자를 모두 출력한다.

해결 방법 : 문자열을 입력받고 N - 1번 반복하며 다음 문자를 확인하고 'J'인 경우 현재 문자를 출력하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : JOI 2022예1 2-3번
*/

char s[128];

int main(void) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] == 'J') printf("%c\n", s[i]);
    }
    return 0;
}