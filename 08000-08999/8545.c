#include <stdio.h>

/*
문제 : 알파벳 세 글자로 이루어진 단어가 주어질 때, 이 단어를 뒤집은 문자열을 구한다.

해결 방법 : 세 문자를 입력받고 순서를 바꿔 출력한다.

주요 알고리즘 : 구현

출처 : PA 2002.11 0-1번
*/

int main(void) {
    char a, b, c;
    scanf("%c%c%c", &a, &b, &c);
    printf("%c%c%c", c, b, a);
    return 0;
}