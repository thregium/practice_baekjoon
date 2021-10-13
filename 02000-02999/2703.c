#include <stdio.h>
#include <ctype.h>

/*
문제 : 대문자와 공백으로 이루어진 100자 이하의 문자열을 문자 순열을 이용해 대문자들을 각각 바꿔서 만든 문자열이 주어진다.
문자 순열이 같이 주어지면 원래의 문자열을 출력한다.

해결 방법 : 원래의 문자열과 순열을 입력 받은 뒤, 알파벳(대문자)이 나오면 순열을 이용해 문자열을 바꾸어 출력하고,
그 외의 것이 나오면 그대로 출력하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : GNY 2008 B번
*/

char mess[128], conv[32];

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        fgets(mess, 120, stdin);
        if (mess[0] == '\n') {
            tt--;
            continue;
        }
        scanf("%s", conv);
        for (int i = 0; mess[i]; i++) {
            if (isupper(mess[i])) printf("%c", conv[mess[i] - 'A']);
            else printf("%c", mess[i]);
        }
    }
    return 0;
}