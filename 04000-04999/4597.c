#include <stdio.h>

/*
문제 : 주어진 길이 32 미만인 이진수의 끝에 패리티가 붙어있다. 패리티에 맞는 이진수로 바꾼 이진수를 출력한다.

해결 방법 : 만약 패리티가 짝수인 경우 지금까지의 1의 개수가 짝수개면 0, 홀수개면 1로 바꾼다.
홀수인 경우에는 반대로 1의 개수가 짝수개면 1, 홀수개면 0으로 바꾼다. 그 다음 바꾼 이진수를 출력하면 된다.

주요 알고리즘 : 구현, 수학

출처 : MidC 2008 A번
*/

char s[64];

int main(void) {
    int c;
    while (1) {
        scanf("%s", s);
        if (s[0] == '#') break;
        c = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'e') {
                if (c & 1) s[i] = '1';
                else s[i] = '0';
                break;
            }
            else if (s[i] == 'o') {
                if (c & 1) s[i] = '0';
                else s[i] = '1';
                break;
            }
            else if (s[i] == '1') c++;
        }
        printf("%s\n", s);
    }
    return 0;
}