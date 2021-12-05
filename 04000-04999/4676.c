#include <stdio.h>
#include <string.h>

/*
문제 : 200자 이하의 3줄로 이루어진 문자열이 주어질 때, 하이쿠의 음율을 따르지 않는 첫 줄을 구한다.
하이쿠는 각 줄의 음절 수가 5개, 7개, 5개여야 한다. 각 음절은 연속한 모음 덩어리의 개수이고, 모음에는 y가 포함된다.
모든 줄이 맞다면 'Y'를 출력한다.

해결 방법 : 문자열을 입력받은 다음, /가 나오기 전까지의 모음의 수를 센다. 단, 앞 글자가 모음인 경우 세지 않는다.
/가 나올 때 마다 그 줄의 음절 수가 맞는지 확인한다. 맞지 않는다면 그 줄의 번호를 출력하고 종료한다.
전부 맞다면 마지막 줄의 음절 수도 확인하고 그 결과를 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : MidC 1997 E번
*/

char s[256];

int isvowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') return 1;
    else return 0;
}

int main(void) {
    int l, c;
    while (1) {
        fgets(s, 240, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        if (!strcmp(s, "e/o/i")) break;

        c = 0, l = 1;
        for (int i = 0; s[i]; i++) {
            if (isvowel(s[i])) {
                if (i > 0 && isvowel(s[i - 1])) continue;
                else c++;
            }
            if (s[i] == '/') {
                if ((l == 1 && c != 5) || (l == 2 && c != 7)) {
                    printf("%d\n", l);
                    break;
                }
                else if (l >= 3) return 1;
                c = 0;
                l++;
            }
        }
        if (l < 3) continue;
        if (c != 5) printf("3\n");
        else printf("Y\n");
    }
    return 0;
}