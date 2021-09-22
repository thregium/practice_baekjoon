#include <stdio.h>
#include <ctype.h>

/*
문제 : 길이 N(N <= 100)의 문자열이 주어질 때, 이 문자열에 최소 몇 자를 추가해야 유효한 비밀번호가 되는지 구한다.
유효한 비밀번호는 6자 이상이고 대문자, 소문자, 숫자, 특수문자를 모두 포함해야 한다.

해결 방법 : ctype헤더의 함수들을 이용해 각 문자들을 대문자, 소문자, 숫자, 특수문자로 분류하고 각각의 등장 여부를 기록한다.
그 후, 등장하지 않은 분류의 개수를 구한다. 만약 이 값이 6 - N보다 작다면 6 - N을 출력하고, 그 외에는 그 값을 출력하면 된다.

주요 알고리즘 : 문자열, 구현
*/

char s[128];
int exist[4];

int main(void) {
    int n, t;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) exist[0] = 1;
        else if (islower(s[i])) exist[1] = 1;
        else if (isupper(s[i])) exist[2] = 1;
        else exist[3] = 1;
    }
    t = (!exist[0]) + (!exist[1]) + (!exist[2]) + (!exist[3]);
    if (6 - n > t) t = 6 - n;
    printf("%d", t);
    return 0;
}