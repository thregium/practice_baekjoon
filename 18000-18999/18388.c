#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 문제에 주어진 문자열을 복호화하여 출력한다. 암호화 방법은 다음과 같다.
대문자가 아닌 문자는 그대로 출력한다.
대문자는 키보드의 한 칸 왼쪽 문자로 출력한다.
입력 또는 출력 문자열은 대소문자와 공백으로만 이루어져 있다.

해결 방법 : 문자열을 입력받은 다음 문제에 쓰인 대로 구현하면 된다. 대문자인 경우
키보드 배치를 하듴코딩한 다음 그 문자열에서 다음 글자를 출력하는 방식으로 간단히 구현 가능하다.

주요 알고리즘 : 문자열, 구현

출처 : Kabul 2018 G번
*/

char s[103000];
char* key = "QWERTYUIOP{ASDFGHJKL:ZXCVBNM<";

int main(void) {
    fgets(s, 101300, stdin);
    for (int i = 0; s[i]; i++) {
        if (isupper(s[i])) {
            for (int j = 0; key[j]; j++) {
                if (s[i] == key[j]) {
                    printf("%c", key[j + 1]);
                }
            }
        }
        else printf("%c", s[i]);
    }
    return 0;
}