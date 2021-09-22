#include <stdio.h>
#include <ctype.h>

/*
문제 : 주어진 길이 L(L <= 100000)의 문자열이 주어질 때, 이 문자열에서 알파벳들을 K(K <= 10^7)칸씩 움직인 결과를 출력한다.
알파벳이 아닌 문자는 그대로 출력하고, 대소문자는 구별해야 한다.

해결 방법 : 각 문자를 살펴보며 알파벳이면 알파벳의 번호를 찾은 다음 K를 더하고 26으로 나눈 나머지를 취한 다음
다시 알파벳으로 바꾸면 된다. 대문자와 소문자에 각각 적용한다. 그 외 문자는 그대로 출력한다.

주요 알고리즘 : 문자열, 구현

출처 : Postech 2018 A번
*/

char s[103000];

int main(void) {
    int k, l;
    scanf("%d %d\n", &k, &l);
    fgets(s, 101300, stdin);
    for (int i = 0; i < l; i++) {
        if (isupper(s[i])) printf("%c", (s[i] - 'A' + k) % 26 + 'A');
        else if (islower(s[i])) printf("%c", (s[i] - 'a' + k) % 26 + 'a');
        else printf("%c", s[i]);
    }
    return 0;
}