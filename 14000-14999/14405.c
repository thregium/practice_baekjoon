#include <stdio.h>

/*
문제 : 길이 5000 이하의 소문자로 이루어진 문자열이 주어지면 이 문자열이 "pi", "ka", "chu" 만으로
만들 수 있는 문자열인지 구한다.

해결 방법 : 문자열의 첫 자부터 보면서 해당 문자열들을 찾는다. 셋 다 아닌 경우가 나오면
그렇게 만들 수 없는 문자열이고, 성공적으로 끝까지 확인했다면 만들 수 있는 문자열이다.

주요 알고리즘 : 구현, 문자열
*/

char s[5120];

int main(void) {
    int r = 1, p = 0;
    scanf("%s", s);
    while (s[p]) {
        if (s[p] == 'p' && s[p + 1] == 'i') p += 2;
        else if (s[p] == 'k' && s[p + 1] == 'a') p += 2;
        else if (s[p] == 'c' && s[p + 1] == 'h' && s[p + 2] == 'u') p += 3;
        else {
            r = 0;
            break;
        }
    }
    printf("%s", r ? "YES" : "NO");
    return 0;
}