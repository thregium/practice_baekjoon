#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 길이 2000 이하의 대소문자로 이루어진 문자열이 주어진다. 각 문자열을 대소문자를 상관하지 않고
같은 알파벳으로 이루어진 그룹으로 나눈 후 앞에서부터 각 알파벳의 처음 나오는 그룹의 크기가
K 이상인 경우 1, 미만인 경우 0으로 나타낸 문자열을 출력한다.

해결 방법 : 문제에 주어진대로 구현한다. tolower()함수와 방문 배열을 사용하는 것이 좋다.

주요 알고리즘 : 구현, 문자열

출처 : 가톨릭대 1회 6번
*/

char s[2048], chk[26];

int main(void) {
    int k, len, last = 0;
    scanf("%s %d", s, &k);
    len = strlen(s);
    for (int i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }
    for (int i = 1; i < len; i++) {
        if (s[i] != s[i - 1]) {
            if (!chk[s[i - 1] - 'a']) {
                printf("%d", i - last >= k);
                chk[s[i - 1] - 'a'] = 1;
            }
            last = i;
        }
    }
    if (!chk[s[len - 1] - 'a']) {
        printf("%d", len - last >= k);
    }
    return 0;
}