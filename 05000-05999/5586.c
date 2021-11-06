#include <stdio.h>

/*
문제 : N(N <= 10000)자 이내의 길이를 가진 문자열이 주어질 때,
이 문자열에서 JOI와 IOI가 각각 몇 번 나오는지 출력한다.

해결 방법 : N과 찾을 문자열이 작으므로 직접 전부 찾아본다.

주요 알고리즘 : 문자열
*/

char s[10240];

int main(void) {
    int joi = 0, ioi = 0;
    scanf("%s", s);
    for (int i = 2; s[i]; i++) {
        if (s[i] == 'I' && s[i - 1] == 'O') {
            if (s[i - 2] == 'J') joi++;
            else if (s[i - 2] == 'I') ioi++;
        }
    }
    printf("%d\n%d", joi, ioi);
    return 0;
}