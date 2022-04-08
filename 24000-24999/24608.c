#include <stdio.h>
#include <string.h>

/*
문제 : 출력 가능한 문자들로 이루어진 길이 100 이하의 문자열이 주어질 때,
이 문자열에 쓰인 문자의 아스키코드 평균값(버림)인 문자를 출력한다.

해결 방법 : 각 문자의 값을 정수형으로 더한 뒤, 길이로 나눈 몫을 구하면 된다. 공백 처리에 주의한다.

주요 알고리즘 : 문자열, 사칙연산

출처 : SCUSA 2021D2 A번 // MidC 2021 A번
*/

char s[128];

int main(void) {
    int l, sum = 0;
    fgets(s, 120, stdin);
    if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
    l = strlen(s);
    for (int i = 0; i < l; i++) {
        if (s[i] < 32 || s[i] > 126) return 1;
        sum += s[i];
    }
    printf("%c", sum / l);
    return 0;
}