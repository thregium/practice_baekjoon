#include <stdio.h>
#include <ctype.h>

/*
문제 : 카이사르 암호로 된 200자 이하의 문자열이 주어질 때, 이를 평문으로 변환한 문자열을 구한다.

해결 방법 : 주어진 문자열을 문자 단위로 살펴본다. 현재 문자가 알파벳이 아니라면 그대로 출력하고, 알파벳이라면
5칸 밀어낸 알파벳을 출력하면 된다. 이는 (buff[i] - 'A' + 21) % 26 + 'A'라는 식을 통해 구현할 수 있다.

주요 알고리즘 : 구현, 문자열

출처 : SCUSA 2002 1번
*/

char buff[256];

int main(void) {
    while (1) {
        scanf("%s\n", &buff);
        if (buff[0] == 'E') break;
        fgets(buff, 250, stdin);
        for (int i = 0; buff[i]; i++) {
            if (isupper(buff[i])) printf("%c", (buff[i] - 'A' + 21) % 26 + 'A');
            else printf("%c", buff[i]);
        }
        scanf("%s", buff);
    }
    return 0;
}