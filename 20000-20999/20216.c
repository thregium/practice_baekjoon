#include <stdio.h>
#include <string.h>

/*
문제 : 어떤 문장이 주어질 때 해당 문장이 어떤 글자로 끝나는 지 확인하고 문자에 따라 서로 다른 출력을 한다.

해결 방법 : strlen(문자열) - 1 또는 - 2를 하면 마지막 글자를 알 수 있다. -1이 \n인 경우 -2를 하면 된다.

주요 알고리즘 : 문자열

출처 : BAPC 2020P D번
*/

char buff[10240];

int main(void) {
    char ld;
    while (1) {
        fgets(buff, 10100, stdin);
        ld = buff[strlen(buff) - 1];
        if (ld == '\n') ld = buff[strlen(buff) - 2];
        if (ld == '.') printf("*Nod*\n");
        else if (ld == '?') printf("Quack!\n");
        else if (ld == '!') return 0;
        else return 1;
        fflush(stdout);
    }
    return 0;
}