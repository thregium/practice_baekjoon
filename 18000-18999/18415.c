#include <stdio.h>

/*
문제 : 길이 N(N <= 100)의 소문자로 이루어진 문자열이 주어질 때, "joi" 부분 문자열을 "JOI"로 바꾼 결과를 출력한다.

해결 방법 : 문자열의 각 자를 찾아가며 그러한 부분이 있는지 확인하고 전부 바꿔나가면 된다.

주요 알고리즘 : 문자열

출처 : JOI 2020예1 3-2번
*/

char s[128];

int main(void) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'j' && s[i + 1] == 'o' && s[i + 2] == 'i') {
            s[i] = 'J';
            s[i + 1] = 'O';
            s[i + 2] = 'I';
        }
    }
    printf("%s", s);
    return 0;
}